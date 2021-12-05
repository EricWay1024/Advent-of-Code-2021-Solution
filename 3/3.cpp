#include "../everything.hpp"

namespace one {
    int cnt[N3][2];
    int n;

    void solve() {
        string s;
        while (cin >> s) {
            n = s.size();
            For(i, n) {
                short c = s[i] - '0';
                cnt[i][c]++;
            }
        }
        int a = 0;
        int b = 0;
        For(i, n) {
            a <<= 1;
            a |= (cnt[i][1] > cnt[i][0]);

            b <<= 1;
            b |= (cnt[i][0] > cnt[i][1]);
        }

        cout << a * b << endl;
    }
}

namespace two {
    int n;

    vector<string> filter(vector<string> &v, int k, int mode) {
        vector<string> u;
        int c[2];
        c[1] = c[0] = 0;
        for (auto &s : v) {
            c[s[k] - '0']++;
        }

        int keep = mode ? (c[1] >= c[0] ? 1 : 0) : (c[0] <= c[1] ? 0 : 1);
        for (auto &s : v) {
            if (s[k] - '0' == keep) u.push_back(s);
        }

        return u;
    }


    int cal(vector<string> v, int mode) {
        int k = 0;
        while (v.size() > 1) {
            v = filter(v, k, mode);
            k++;
        }
        auto s = v[0];
        int t = 0;
        for (char c : s) {
            t <<= 1;
            t += c - '0';
        }
        return t;
    }

    void solve() {
        string s;
        vector<string> v;
        while (cin >> s) {
            n = s.size();
            v.push_back(s);
        }
        int a = cal(v, 1);
        int b = cal(v, 0);
        cout << a * b << endl;
    }
}


int main() {
    freopen("3.in", "r", stdin);
    // one::solve();
    two::solve();

    return 0;
}