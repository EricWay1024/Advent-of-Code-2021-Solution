#include "../everything.hpp"

map<string, char> mp;

ll mem[30][30][100][30];
ll vis[30][30][100];
void dp(char a, char b, int k) {
    int p = a - 'A';
    int q = b - 'A'; 
    if (vis[p][q][k]) return; 
    vis[p][q][k] = 1;
    string t; t.push_back(a); t.push_back(b);
    if (!mp[t]) {
        mem[p][q][k][q] = 1;
        return; 
    }
    int r = mp[t] - 'A';

    if (k == 1) {
        mem[p][q][k][r]++;
        mem[p][q][k][q]++;
    }

    else {
        dp(a, mp[t], k - 1);
        dp(mp[t], b, k - 1);
        rep(i,0,25) {
            mem[p][q][k][i] = mem[p][r][k - 1][i] + mem[r][q][k - 1][i];
        }
    } 
}

ll cal(string s, int k) {
    map<char, ll> cnt;
    cnt[s[0]] = 1;
    For(i, s.size() - 1) {
        dp(s[i], s[i + 1], k);
        rep(j,0,25) cnt[j + 'A'] += mem[s[i] - 'A'][s[i + 1] - 'A'][k][j];
    }

    ll mx = 0; ll mn = INT64_MAX;
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

    ll res = cal(s, 40);
    cout << res << endl;
}

int main() {
    freopen("14.in", "r", stdin);
    solve();
    return 0;
}