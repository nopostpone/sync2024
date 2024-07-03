struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
     
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
         
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
     
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
     
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
         
        int d = dep[u] - k;
         
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
         
        return seq[in[u] - dep[u] + d];
    }
     
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
     
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
     
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
     
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};
 
 
// S: return type, op: how to merge at return, e: S default constructor
// F: value type of lazy value
// mapping: called on apply() to each item, mapping(F f, S item)
// composition: called on apply() to lazy value of a seg, composition(F f, F lazy)
// id: default falue of lazy value
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) ++log;
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
 
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
 
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
 
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
 
        l += size;
        r += size;
 
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
 
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
 
        return op(sml, smr);
    }
 
    S all_prod() { return d[1]; }
 
    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
 
        l += size;
        r += size;
 
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
 
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
 
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
 
    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
 
    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
 
  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;
 
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

array<int, 3> tmp[100];
int tmpcnt = 0;

template <
		typename E,
		E (*merge_node_value)(E, E),
		E (*default_node_value)(),
        typename F,
        E (*do_operation_on)(F, E),
        F (*merge_operation)(F, F),
        F (*default_operation)()
>
struct HLDPathQuery : HLD {
    using seg_tree = lazy_segtree<E, merge_node_value, default_node_value, F, do_operation_on, merge_operation, default_operation>;
	vector<seg_tree> downtree, uptree;
	vector<int> tot;
	
	HLDPathQuery(int n) : HLD(n), downtree(n), uptree(n), tot(n) {
	    
	}
	
	void work(int root = 0) {
	    HLD::work(root);
	    for (int i = 0; i < n; i++) tot[top[i]]++;
	    for (int i = 0; i < n; i++) {
	        if (top[i] == i) downtree[i] = uptree[i] = seg_tree(tot[i]);
	    }
	}
	
	
	void iteratePath(int u, int v, function<void(int, int, int)> f) {
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]]) {
				f(top[u], in[u] - in[top[u]], 0);
				u = parent[top[u]];
			} else {
			    tmp[++tmpcnt] = {top[v], 0, in[v] - in[top[v]]};
				v = parent[top[v]];
			}
		}
		f(top[u], in[u] - in[top[u]], in[v] - in[top[u]]);
		while (tmpcnt) {
			f(tmp[tmpcnt][0], tmp[tmpcnt][1], tmp[tmpcnt][2]);
			tmpcnt--;
		}
	}
	
	E queryPath(int u, int v) {
		E ans = default_node_value();
		int hasans = 0;
		iteratePath(u, v, [&](int x, int l, int r) -> void {
		    E cur = l > r ? uptree[x].prod(tot[x] - l - 1, tot[x] - r) : downtree[x].prod(l, r + 1);
			if (!hasans) {
				ans = cur;
				hasans = 1;
			} else {
				ans = merge_node_value(ans, cur);
			}
		});
		return ans;
	}
	
	void updatePath(int u, int v, F f) {
		iteratePath(u, v, [&](int x, int l, int r) -> void {
		    if (l > r) swap(l, r);
		    uptree[x].apply(tot[x] - r - 1, tot[x] - l, f);
		    downtree[x].apply(l, r + 1, f);
		});
	}
	
	void updatePoint(int u, E e) {
		uptree[top[u]].set(tot[top[u]] - (in[u] - in[top[u]]) - 1, e);
		downtree[top[u]].set(in[u] - in[top[u]], e);
	}
	
	E queryPoint(int u) {
		return downtree[top[u]].get(in[u] - in[top[u]]);
	}
};

struct node {
	int premin;
	int premax;
	int sufmin;
	int sufmax;
	int sum;
	int maxans;
	int minans;
};
 
using E = node;
 
E merge_node_value(E a, E b) {
	E ans;
	ans.maxans = max({a.maxans, b.maxans, a.sufmax + b.premax});
	ans.minans = min({a.minans, b.minans, a.sufmin + b.premin});
	ans.premax = max(a.premax, a.sum + b.premax);
	ans.sufmax = max(b.sufmax, b.sum + a.sufmax);
	ans.premin = min(a.premin, a.sum + b.premin);
	ans.sufmin = min(b.sufmin, b.sum + a.sufmin);
	ans.sum = a.sum + b.sum;
	return ans;
}
 
E default_node_value() {
	return {0, 0, 0, 0, 0, 0};
}
 
using F = int;
 
E do_operation_on(F f, E e) {
	return e;
}
 
F merge_operation(F a, F b) {
	return 0;
}
 
F default_operation() {
	return 0;
}
 
void solve() {
	int n;
	cin >> n;
	HLDPathQuery<E, merge_node_value, default_node_value, F, do_operation_on, merge_operation, default_operation> hld(n + 1);
	vector<int> w(n + 1);
	
	vector<array<int, 3>> qry;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		char op;
		cin >> op;
		if (op == '+') {
			int v, x;
			cin >> v >> x;
			v--;
			w[++tot] = x;
			hld.addEdge(tot, v);
		} else {
			int u, v, k;
			cin >> u >> v >> k;
			u--, v--;
			qry.push_back({u, v, k});
		}
	}
	hld.work(0);
	w[0] = 1;
	for (int i = 0; i <= tot; i++) {
		E e;
		e.premin = e.sufmin = e.premax = e.sufmax = w[i];
		e.maxans = max(0, w[i]);
		e.minans = min(0, w[i]);
		e.sum = w[i];
		hld.updatePoint(i, e);
	}
	for (auto q : qry) {
		auto ans = hld.queryPath(q[0], q[1]);
		//out2(ans.maxans, ans.minans);
		if (ans.minans <= q[2] && q[2] <= ans.maxans) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}


array<int, 3> tmp[100];
int tmpcnt = 0;

struct HLDPathQuery : HLD {
    vector<int> tot;
     
    HLDPathQuery(int n) : HLD(n) {
         
    }
     
    void work(int root = 0) {
        HLD::work(root);
    }
     
    void iteratePath(int u, int v, function<void(int, int, int, int)> f) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                f(top[u], 0, in[u] - in[top[u]], 1);
                u = parent[top[u]];
            } else {
                tmp[++tmpcnt] = {top[v], 0, in[v] - in[top[v]]};
                v = parent[top[v]];
            }
        }
        int flag = in[u] > in[v];
        if (flag) swap(u, v);
        f(top[u], in[u] - in[top[u]], in[v] - in[top[u]], flag);
        while (tmpcnt) {
            f(tmp[tmpcnt][0], tmp[tmpcnt][1], tmp[tmpcnt][2], 0);
            tmpcnt--;
        }
    }
};