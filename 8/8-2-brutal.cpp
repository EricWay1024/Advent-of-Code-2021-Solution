#include "../everything.hpp"

char ans[300];

string translate(string s) {
    string t;
    for (auto &c: s) {
        t.push_back(ans[c]);
    }
    sort(t.begin(), t.end());
    return t;
}

void solve() {
    ll res = 0;
    vector<string> standard = {
        "abcefg", "cf", "acdeg",
        "acdfg", "bcdf", "abdfg",
        "abdefg", "acf", "abcdefg", 
        "abcdfg"
    };
    for (auto &s: standard) {
        sort(s.begin(), s.end());
    }
    map<string, int> dict;
    rep(i, 0, 9) dict[standard[i]] = i;
    sort(standard.begin(), standard.end());

    whileneof {
        vector<string> v;
        rep(c, 'a', 'g') ans[c] = c;
        string s;
        rep(i,1,10) {
            cin >> s;
            v.push_back(s);
        }
        do {
            vector<string> u;
            for (auto &s: v) {
                u.push_back(translate(s));
            }
            sort(u.begin(), u.end());
            if (u == standard) break;
        } while (next_permutation(ans + 'a', ans + 'g' + 1));

        cin >> s;
        ll a = 0;
        rep(i,1,4) {
            cin >> s;
            a = a * 10 + dict[translate(s)];
        }
        res += a;
    }
    cout << res << endl;
}

int main() {
    freopen("8.in", "r", stdin);
    solve();
    return 0;
}