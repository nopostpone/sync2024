#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

// 检测两个时间段是否相交
constexpr bool intersect(int x, int y, int l, int r) {
    return min(y, r) > max(x, l);
}

struct Reserve {
    int student;
    int room;
    int st;
    int ed;

    Reserve(int student, int room, int start, int duration) 
        : student(student), room(room), st(start), ed(start + duration) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int N = 1000;

    vector<Reserve> a; // 存放预约的信息

    array<int, N> violate{};
    array<unordered_set<int>, N> r{}, s{};

    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "cancel") {
            int id;
            cin >> id;
            id--;

            bool success = false;
            auto [student, room, _, __] = a[id];
            if (r[room].contains(id)) {
                success = true;
                r[room].erase(id);
                s[student].erase(id);
            }
            
            cout << (success ? "SUCCESS" : "FAIL") << "\n";
            continue;
        }

        int student, room, duration;
        string _start;
        cin >> student >> room >> _start >> duration;

        bool valid = true;
        bool success = true;

        // 如果这个人已经黑名单了，直接拒绝
        if (violate[student] >= 3) {
            success = valid = false;
        }

        // 时间转化为整数
        int start = stoi(_start.substr(0, 2)) * 60 + stoi(_start.substr(3));


        // 0. 时间大于两小时直接违规
        if (duration > 120) {
            success = valid = false;
        }

        // 1. 看他自己所有的预约，有没有冲突
        for (auto id : s[student]) {
            if (intersect(a[id].st, a[id].ed, start, start + duration)) {
                success = valid = false;
            }
        }

        // 2. 看他预约的教室，有没有冲突
        for (auto id : r[room]) {
            if (intersect(a[id].st, a[id].ed, start, start + duration)) {
                success = false;
            }
        }

        if (not valid) {
            // 检查是不是要把他之前的预约清空
            violate[student]++;
            if (violate[student] >= 2) {
                for (auto id : s[student]) {
                    r[a[id].room].erase(id);
                }
                s[student].clear();
            }
        }
        if (success) {
            int id = a.size();
            r[room].insert(id);
            s[student].insert(id);

            a.emplace_back(student, room, start, duration);
            cout << "SUCCESS " << id + 1 << "\n";
        } else {
            cout << "FAIL\n";
        }
    }
    

    return 0;
}