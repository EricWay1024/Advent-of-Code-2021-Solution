#include "../everything.hpp"

const int N = 100; // number of numbers drawn
const int M = 100; // number of boards

namespace one {
    int a[N2];
    int b[N2][N1][N1];
    int mark[N2][N1][N1];
    int col[N2][N1];
    int row[N2][N1];

    vector< tuple<int, int, int> > mp[N2];
    void solve() {
        rep(i,1,N) rin >> a[i];

        rep(i,1,M) rep(j,1,5) rep(k,1,5) {
            rin >> b[i][j][k]; 
            mp[b[i][j][k]].push_back(make_tuple(i, j, k)); 
        }

        rep(l,1,N) {
            int u = a[l];
            for (auto &[i, j, k] : mp[u]) {
                if (!mark[i][j][k]) {
                    mark[i][j][k] = 1;
                    col[i][j]++;
                    row[i][k]++;

                    if (col[i][j] == 5 || row[i][k] == 5) {
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
}

namespace two {
    int a[N2];
    int b[N2][N1][N1];
    int mark[N2][N1][N1];
    int col[N2][N1];
    int row[N2][N1];
    set<int> win;
    vector< tuple<int, int, int> > mp[N2];

    void solve() {
        rep(i,1,N) rin >> a[i];

        rep(i,1,M) rep(j,1,5) rep(k,1,5) {
            rin >> b[i][j][k]; 
            mp[b[i][j][k]].push_back(make_tuple(i, j, k)); 
        }

        rep(l,1,N) {
            int u = a[l];
            for (auto &[i, j, k] : mp[u]) {
                if (!mark[i][j][k]) {
                    mark[i][j][k] = 1;
                    col[i][j]++;
                    row[i][k]++;

                    if (col[i][j] == 5 || row[i][k] == 5) {
                        win.insert(i);
                        if (win.size() == M) {
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
    }
}
int main() {
    freopen("4.in", "r", stdin);
    // one::solve();
    two::solve();


    return 0;
}