#include "../everything.hpp"

const int N = 120;
const int O = 55;
int on[N][N][N];
void solve() {
    whileneof {
        char o; cin >> o >> o;
        int xa, xb, ya, yb, za, zb;
        rin >> xa >> xb >> ya >> yb >> za >> zb;
        xa = max(-50, xa);
        ya = max(-50, ya);
        za = max(-50, za);
        xb = min(50, xb);
        yb = min(50, yb);
        zb = min(50, zb);

        rep(i,xa,xb) rep(j,ya,yb) rep(k,za,zb) {
            on[i + O][j + O][k + O] = (o == 'n');
        }
    }

    int res = 0;
    rep(i,-50,50) rep(j,-50,50) rep(k,-50,50) {
        res += on[i + O][j + O][k + O];
    }
    cout << res << endl;
}

int main() {
    freopen("22.in", "r", stdin);
    solve();
    return 0;
}