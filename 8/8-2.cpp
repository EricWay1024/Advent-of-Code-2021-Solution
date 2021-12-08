#include "../everything.hpp"

bool in(char c, string &s) {
    return s.find(c) < s.size();
}

void solve() {
    ll res = 0;

    while (1) {
        map<int, vector<string>> mp;
        map<char, int> cnt;
        map<char, int> cntwa;
        map<char, char> ans;
        map<string, int> dict;
        vector<string> all_str;

        string s;
        rep(i,1,10) {
            cin >> s;
            sort(s.begin(), s.end());
            mp[s.size()].push_back(s);
            all_str.push_back(s);
            for (char c: s) {
                cnt[c]++;
            }
        }

        dict[mp[2][0]] = 1;
        dict[mp[4][0]] = 4;
        dict[mp[3][0]] = 7;
        dict[mp[7][0]] = 8;

        auto seven = mp[3][0];
        for (char c: seven) {
            if (!in(c, mp[2][0])) ans['a'] = c;
        }

        for (auto s: all_str) {
            bool k = 0;
            for (char c: s) {
                if (c == ans['a']) k = 1;
            }
            if (k) {
                for (char c: s) cntwa[c]++;
            }
        }

        for (auto [c, i]: cnt) {
            if (i == 8 && c != ans['a']) ans['c'] = c;
            if (i == 6) ans['b'] = c;
            if (i == 4) ans['e'] = c;
            if (i == 9) ans['f'] = c;
            if (i == 7 && cntwa[c] == 6) ans['d'] = c;
            if (i == 7 && cntwa[c] == 7) ans['g'] = c;
        }

        for (auto s: mp[5]) {
            if (in(ans['c'], s) && in(ans['e'], s)) dict[s] = 2;
            if (in(ans['c'], s) && in(ans['f'], s)) dict[s] = 3;
            if (in(ans['b'], s) && in(ans['f'], s)) dict[s] = 5;
        }

        for (auto s: mp[6]) {
            if (in(ans['c'], s) && in(ans['e'], s)) dict[s] = 0;
            if (in(ans['d'], s) && in(ans['e'], s)) dict[s] = 6;
            if (in(ans['c'], s) && in(ans['d'], s)) dict[s] = 9;
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
        // logs(t);
        
        cin >> ws;
        if (cin.peek() == -1) break;
    }
    cout << res << endl;
}

int main() {
    freopen("8.in", "r", stdin);
    solve();
    return 0;
}