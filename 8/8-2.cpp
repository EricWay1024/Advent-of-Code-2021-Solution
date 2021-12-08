#include "../everything.hpp"

bool in(char c, string &s) {
    return s.find(c) < s.size();
}

void solve() {
    ll res = 0;

    whileneof {
        map<int, vector<string>> mp;
        map<char, int> cnt;
        map<char, char> ans;
        map<string, int> dict;

        string s;
        rep(i,1,10) {
            cin >> s;
            sort(s.begin(), s.end());
            mp[s.size()].push_back(s);
            for (char c: s) {
                cnt[c]++;
            }
        }

        auto seven = mp[3][0];
        auto four = mp[4][0];
        auto one = mp[2][0];
        dict[one] = 1;
        dict[four] = 4;
        dict[seven] = 7;
        dict[mp[7][0]] = 8;

        for (char c: seven) {
            if (!in(c, one)) ans['a'] = c;
        }

        for (auto [c, i]: cnt) {
            if (i == 8 && c != ans['a']) ans['c'] = c;
            if (i == 6) ans['b'] = c;
            if (i == 4) ans['e'] = c;
            if (i == 9) ans['f'] = c;
            if (i == 7) {
                if (in(c, four)) ans['d'] = c;
                else ans['g'] = c;
            }
        }

        for (auto s: mp[5]) {
            if (in(ans['c'], s) && in(ans['e'], s)) dict[s] = 2;
            if (in(ans['c'], s) && in(ans['f'], s)) dict[s] = 3;
            if (in(ans['b'], s) && in(ans['f'], s)) dict[s] = 5;
        }

        for (auto s: mp[6]) {
            if (!in(ans['d'], s)) dict[s] = 0;
            if (!in(ans['c'], s)) dict[s] = 6;
            if (!in(ans['e'], s)) dict[s] = 9;
        }

        cin >> s;
        ll t = 0;
        rep(i,1,4) {
            cin >> s;
            sort(s.begin(), s.end());
            t *= 10;
            t += dict[s];
        }
        res += t;
    }

    cout << res << endl;
}

int main() {
    freopen("8.in", "r", stdin);
    solve();
    return 0;
}