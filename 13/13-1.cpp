#include "../everything.hpp"

const int N = 3 * N3;
int game[N][N];
const int M = 782; // number of points

void fold(char c, int t) {
    if (c == 'x') {
        rep(i,1,t) {
            rep(j,0,N-1) {
                game[t - i][j] |= game[t + i][j];
                game[t + i][j] = 0;
            }
        }
    }
    if (c == 'y') {
        rep(i,1,t) {
            rep(j,0,N-1) {
                game[j][t - i] |= game[j][t + i];
                game[j][t + i] = 0;
            }
        }
    }
}

int count() {
    int k = 0;
    For(i,N) For(j,N) k += game[i][j];
    return k;
}

void solve() {
    rep(i,1,M) {
        int x, y;
        rin >> x >> y;
        game[x][y] = 1;
    }

    string s; char c, o; int x;
    cin >> s >> s >> c >> o >> x;
    fold(c, x);
    cout << count() << endl;
}

int main() {
    freopen("13.in", "r", stdin);
    solve();
    return 0;
}