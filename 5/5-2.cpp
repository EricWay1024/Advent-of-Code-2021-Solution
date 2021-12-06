#include "../everything.hpp"

int game[N3][N3];

void solve() {
    int a, b, x, y;
    char o;
    while (cin >> a >> o >> b >> o >> o >> x >> o >> y) {
        if (a == x) {
            rep(i,min(b,y),max(b,y)) game[a][i]++;
        } else if (b == y) {
            rep(i,min(a,x),max(a,x)) game[i][b]++;
        } else if (y - b == x - a) {
            int k = abs(y - b);
            rep(i,0,k) game[min(a, x) + i][min(b, y) + i]++;
        } else if (y - b == a - x) {
            int k = abs(y - b);
            rep(i,0,k) game[min(a, x) + i][max(b, y) - i]++;
        }
    }

    int cnt = 0;
    rep(i,0,1000) rep(j,0,1000) if (game[i][j] >= 2) cnt++;
    cout << cnt << endl;
}

int main() {
    freopen("5.in", "r", stdin);
    solve();
    return 0;
}