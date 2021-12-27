#include "../everything.hpp"

const int N = 2;
const int ENERGY[] = {0, 1, 10, 100, 1000};
const int COLS[] = {2, 4, 6, 8};
const int M = 1e6 + 7;
vector<string> v;

struct State {
    vector<int> a[4];
    int b[11];
    ll expense;

    void init() {
        For(i, 4) {
            For(j, N) {
                a[i].push_back(v[j + 2][COLS[i] + 1] - 'A' + 1);
            }
            reverse(a[i].begin(), a[i].end());
        }
        For(i, 11) b[i] = 0;
        expense = 0;
    }

    bool operator==(const State &c) const {
        For(i, 4) {
            if (a[i] != c.a[i]) return 0;
        }
        For(i, 11) {
            if (b[i] != c.b[i]) return 0;
        }
        return 1;
    }

    int my_hash() {
        int res = 1;
        For(i, 4) {
            for (auto j: a[i]) {
                res *= 113;
                res += j ^ a[i].size();
                res %= M;
            }
        }

        For(i, 11) {
            if (b[i]) {
                res *= 1023;
                res += b[i] ^ i;
                res %= M;
            }
        }

        return (res + M) % M;
    }

    // void output() {
    //     logs(expense)
    //     For(i, 4) {
    //         cout << i << ": ";
    //         for (auto j: a[i]) {
    //             cout << j << " ";
    //         }
    //         cout << endl;
    //     }
    //     For(i, 11) cout << b[i] << " ";
    //     cout << endl << endl;
    // }
};

queue<State> q;
vector<State> vis[M];

bool try_insert(State &x) {
    int h = x.my_hash();
    for (auto &y: vis[h]) {
        if (x == y) {
            if (x.expense >= y.expense) return 0;
            else {
                y.expense = x.expense;
                return 1;
            }
        }
    }
    vis[h].push_back(x);
    return 1;
}

void try_push_to_q(State &x) {
    if (try_insert(x)) q.push(x);
}

ll bfs() {
    State st;
    st.init();
    try_push_to_q(st);

    ll ans = INT64_MAX;
    while (q.size()) {
        State x = q.front(); q.pop();

        bool is_finish = 1;
        bool flag[4];
        For(i, 4) {
            flag[i] = 1;
            if (x.a[i].size() < N) is_finish = 0;
            for (auto t: x.a[i]) {
                if (t != i + 1) {
                    flag[i] = 0;
                    is_finish = 0;
                    break;
                }
            }
        }

        if (is_finish) {
            ans = min(ans, x.expense);
            continue;
        }

        For(i, 4) if (!flag[i]) {
            int c = COLS[i];
            vector<int> temp;

            rep(j, c + 1, 10) {
                if (j == 2 || j == 4 || j == 6 || j == 8) continue;
                if (x.b[j]) break;
                temp.push_back(j);
            }

            rev(j, c - 1, 0) {
                if (j == 2 || j == 4 || j == 6 || j == 8) continue;
                if (x.b[j]) break;
                temp.push_back(j);
            }

            for (auto j: temp) {
                State y = x;
                ll step = N - y.a[i].size() + abs(c - j) + 1;
                int t = y.a[i].back();
                y.expense += step * ENERGY[t];
                y.a[i].pop_back();
                y.b[j] = t;
                try_push_to_q(y);
            }
        }

        For(i, 4) if (flag[i] && x.a[i].size() < N) {
            int c = COLS[i];
            vector<int> temp;
            rep(j, c + 1, 10) {
                if (x.b[j]) {
                    if (x.b[j] == i + 1) temp.push_back(j);
                    break;
                }
            }

            rev(j, c - 1, 0) {
                if (x.b[j]) {
                    if (x.b[j] == i + 1) temp.push_back(j);
                    break;
                }
            }

            for (auto j: temp) {
                State y = x;
                ll step = N - y.a[i].size() + abs(c - j);
                int t = i + 1;
                y.expense += step * ENERGY[t];
                y.a[i].push_back(t);
                y.b[j] = 0;
                try_push_to_q(y);
            }
        }
    }

    return ans;
}

void solve() {
    string s; 
    whileneof {
        getline(cin, s);
        if (s.length() < 13) {
            s = "##" + s + "##";
        }
        v.push_back(s);
    }

    cout << bfs() << endl;

}

int main() {
    freopen("23-1.in", "r", stdin);
    solve();
    return 0;
}