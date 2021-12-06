#include "../everything.hpp"

int b[N2][N1][N1];
int mark[N2][N1][N1];
int col[N2][N1];
int row[N2][N1];
vector< tuple<int, int, int> > mp[N2];

void solve() {
    string s; cin >> s;
    auto a = map_to_ll(split(s, ','));
    int m = 0;
    while (1) {
        m++;
        rep(j,1,5) rep(k,1,5) {
            cin >> b[m][j][k]; 
            mp[b[m][j][k]].push_back(make_tuple(m, j, k)); 
        }
        cin >> ws;
        if (!~cin.peek()) break;
    }

    for (auto u : a) {
        for (auto &[i, j, k] : mp[u]) {
            if (!mark[i][j][k]) {
                mark[i][j][k] = 1;
                row[i][j]++;
                col[i][k]++;
                if (col[i][k] == 5 || row[i][j] == 5) {
                    ll res = 0;
                    rep(x,1,5) rep(y,1,5) if (!mark[i][x][y]) res += b[i][x][y];
                    res *= u;
                    cout << res << endl;
                    return;
                }
                
            }
        }
    }
}

int main() {
    freopen("4.in", "r", stdin);
    solve();
    return 0;
}