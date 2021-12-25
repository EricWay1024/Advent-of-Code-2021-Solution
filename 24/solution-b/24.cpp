#include "../everything.hpp"

struct Function {
    int type;
    int a, b;

    int operator() (int w, int z) {
        if (type == 1) {
            return w + 26 * z + a;
        } else {
            return (w + a - z) % 26 == 0 ? z / 26 : 26 * (z / 26) + w + b;
        }
    }

    vector<pii> inv(int r) {
        vector<pii> res;
        if (type == 1) {
            r -= a;
            rep(w, 1, 9) {
                int t = r - w;
                if (t >= 0 && t % 26 == 0) {
                    int z = t / 26;
                    res.emplace_back(w, z);
                }
            }
        } else {
            int z0 = r * 26;
            rep(w, 1, 9) {
                int z = z0 + w + a;
                res.emplace_back(w, z);

                if (r > b) {
                    int t = r - w - b;
                    if (t >= 0 && t % 26 == 0) {
                        int z1 = (t / 26) * 26;
                        For(i, 26) {
                            int z2 = z1 + i;
                            if ((w + a - z2) % 26) res.emplace_back(w, z2);
                        }
                    }
                }
            }
        }
        return res;
    }
} fs[14];

int get_int(string &s) {
    istringstream iss(s);
    string o; int a;
    iss >> o >> o >> a;
    return a;
}

string ans = "00000000000000";
string cmax = "00000000000000";
string cmin = "99999999999999";
void dfs(int cur, int r) {
    if (cur == -1) {
        if (r == 0) {
            cmax = max(cmax, ans);
            cmin = min(cmin, ans);
        }
        return;
    }

    auto prev = fs[cur].inv(r);
    for (auto [w, z]: prev) {
        ans[cur] = w + '0';
        dfs(cur - 1, z);
    }
}

void solve() {
    string s;
    For(i, 14) {
        vector<string> v;
        For(j, 18) {
            getline(cin, s);
            v.push_back(s);
        }
        if (v[4] == "div z 1") {
            fs[i].type = 1;
            fs[i].a = get_int(v[15]);
        } else {
            fs[i].type = 2;
            fs[i].a = -get_int(v[5]);
            fs[i].b = get_int(v[15]);
        }
    }

    dfs(13, 0);
    cout << cmax << endl << cmin << endl;
}

int main() {
    freopen("24.in", "r", stdin);
    solve();
    return 0;
}