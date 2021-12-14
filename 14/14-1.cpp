#include "../everything.hpp"

map<string, char> mp;

string step(string s) {
    string res;
    res.push_back(s[0]);
    For(i, s.size() - 1) {
        string t;
        t.push_back(s[i]);
        t.push_back(s[i + 1]);
        if (mp[t]) {
            res.push_back(mp[t]);
            res.push_back(s[i + 1]);
        } else {
            res.push_back(s[i + 1]);
        }
    }
    return res;
}

int cal(string s) {
    map<char, int> cnt;
    for (char c: s) {
        cnt[c]++;
    }

    int mx = 0; int mn = s.size() + 1;
    rep(c,'A','Z') {
        mx = max(mx, cnt[c]);
        if (cnt[c]) mn = min(mn, cnt[c]);
    }
    return mx - mn;
}


void solve() {
    string s;
    cin >> s;
    whileneof {
        string t; char o, c;
        cin >> t >> o >> o >> c;
        mp[t] = c;
    }

    rep(i,1,10) {
        s = step(s);
    }
    ll res = cal(s);
    cout << res << endl;
}

int main() {
    freopen("14.in", "r", stdin);
    // freopen("14.test", "r", stdin);
    solve();
    return 0;
}