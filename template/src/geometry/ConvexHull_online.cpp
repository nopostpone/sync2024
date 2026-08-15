// struct Point { ... };
constexpr double EPS = 1e-9;

template <class T>
auto earCut(std::vector<Point<T>> p) {
    std::vector<std::vector<Point<T>>> res;
    while (p.size() > 2) {
        int n = p.size();
        bool found = false;
        for (int i = 0; i < n; i++) {
            int l = (i - 1 + n) % n;
            int r = (i + 1) % n;

            if (cross(p[i] - p[l], p[r] - p[i]) <= 0) {
                continue;
            }
            bool empty = true;
            for (int j = 0; j < n; j++) {
                if (j == i or j == l or j == r) {
                    continue;
                }
                auto l1 = p[i] - p[l];
                auto l2 = p[r] - p[i];
                auto l3 = p[l] - p[r];

                auto c1 = cross(l1, p[j] - p[l]);
                auto c2 = cross(l2, p[j] - p[i]);
                auto c3 = cross(l3, p[j] - p[r]);

                bool neg = (c1 < 0) or (c2 < 0) or (c3 < 0);
                bool pos = (c1 > 0) or (c2 > 0) or (c3 > 0);

                if (not(neg and pos)) {
                    empty = false;
                    break;
                }
            }
            if (not empty) {
                continue;
            }

            res.push_back({p[l], p[i], p[r]});
            p.erase(p.begin() + i);
            found = true;
            break;
        }
        if (not found) {
            break;
        }
    }
    for (auto &p : res) {
        int st = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i].y < p[st].y || (p[i].y == p[st].y && p[i].x < p[st].x)) {
                st = i;
            }
        }
        std::rotate(p.begin(), p.begin() + st, p.end());
    }

    return res;
}

// O(V^2 log(V))
template <typename T>
double convexPolygonsUnionArea(std::vector<std::vector<Point<T>>> polygons) {
    for (auto &poly : polygons) {
        if (poly.size() < 3)
            continue;
        T area2 = 0;
        for (size_t i = 0; i < poly.size(); i++) {
            area2 += cross(poly[i], poly[(i + 1) % poly.size()]);
        }
        if (area2 < 0) {
            std::reverse(poly.begin(), poly.end());
        }
    }

    double res = 0;
    int n = polygons.size();

    for (int i = 0; i < n; i++) {
        int m_i = polygons[i].size();
        if (m_i < 3)
            continue;

        for (int e_idx = 0; e_idx < m_i; e_idx++) {
            Point<T> P = polygons[i][e_idx];
            Point<T> Q = polygons[i][(e_idx + 1) % m_i];
            Point<T> D = Q - P;

            std::vector<std::pair<double, double>> intervals;

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int m_j = polygons[j].size();
                if (m_j < 3)
                    continue;

                double L = 0.0, R = 1.0;
                bool valid = true;

                for (int k = 0; k < m_j; k++) {
                    Point<T> U = polygons[j][k];
                    Point<T> V = polygons[j][(k + 1) % m_j];
                    Point<T> E = V - U;

                    T A = cross(E, D);
                    T B = cross(E, P - U);

                    if (A > 0) {
                        L = std::max(L, (double)(-B) / A);
                    } else if (A < 0) {
                        R = std::min(R, (double)(-B) / A);
                    } else {
                        if (B < 0) {
                            valid = false;
                            break;
                        } else if (B == 0) {
                            if (dot(E, D) > 0 && j < i) {
                                valid = false;
                                break;
                            }
                        }
                    }
                }
                if (valid && L < R - EPS) {
                    intervals.push_back({std::max(0.0, L), std::min(1.0, R)});
                }
            }

            std::sort(intervals.begin(), intervals.end());
            double cur_R = 0.0;
            double edge_integral = 0.0;

            for (const auto &intv : intervals) {
                if (intv.first > cur_R + EPS) {
                    edge_integral += (intv.first - cur_R);
                }
                cur_R = std::max(cur_R, intv.second);
            }
            if (cur_R < 1.0 - EPS) {
                edge_integral += (1.0 - cur_R);
            }

            T base_cross = cross(P, D);
            res += edge_integral * base_cross;
        }
    }
    return res / 2.0;
}

template <class T>
std::vector<Point<T>> convexHull(std::vector<Point<T>> pts) {
    std::sort(pts.begin(), pts.end(), [](const auto &a, const auto &b) {
        return a.x < b.x or (a.x == b.x and a.y < b.y);
    });
    pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 2) {
        return pts;
    }

    std::vector<Point<T>> hull;

    for (const auto &p : pts) {
        while (hull.size() >= 2) {
            auto v1 = hull.back() - hull[hull.size() - 2];
            auto v2 = p - hull.back();
            if (cross(v1, v2) <= 0) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }

    int t = hull.size() + 1;
    for (int i = (int)pts.size() - 2; i >= 0; i--) {
        while (hull.size() >= t) {
            auto v1 = hull.back() - hull[hull.size() - 2];
            auto v2 = pts[i] - hull.back();

            if (cross(v1, v2) <= 0) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(pts[i]);
    }

    hull.pop_back();
    return hull;
}

// convex + convex, counterclockwise
// O(n + m)
template <class T>
std::vector<Point<T>> minkowski(const std::vector<Point<T>> &a, const std::vector<Point<T>> &b) {
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) {
        return {};
    }

    std::vector<Point<T>> c;
    c.reserve(n + m + 1);
    c.push_back(a[0] + b[0]);
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        auto va = a[(i + 1) % n] - a[i];
        auto vb = b[(j + 1) % m] - b[j];

        auto v = cross(va, vb);
        if (v > 0) {
            c.push_back(c.back() + va);
            i++;
        } else if (v < 0) {
            c.push_back(c.back() + vb);
            j++;
        } else {
            c.push_back(c.back() + va + vb);
            i++;
            j++;
        }
    }
    
    while (i < n) {
        c.push_back(c.back() + a[(i + 1) % n] - a[i]);
        i++;
    }
    while (j < m) {
        c.push_back(c.back() + b[(j + 1) % m] - b[j]);
        j++;
    }
    
    c.pop_back();
    return c;
}