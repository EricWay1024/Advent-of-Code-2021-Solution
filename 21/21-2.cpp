#include "../everything.hpp"

ll c[12];
ll mem[12][12][30][30][2][2];

ll f(ll a, ll b, ll x, ll y, bool flag, int win) {
    if (x <= 0) return win;
    if (y <= 0) return 1 - win;

    ll &ans = mem[a][b][x][y][flag][win];
    if (ans != -1) return ans;

    ll res = 0;
    if (flag) {
        rep(i,3,9) {
            ll na = (a + i + 9) % 10 + 1;
            res += c[i] * f(na, b, x - na, y, !flag, win);
        }
    }
    else {
        rep(i,3,9) {
            ll nb = (b + i + 9) % 10 + 1;
            res += c[i] * f(a, nb, x, y - nb, !flag, win);
        }
    }
    return ans = res;
}

void solve() {
    int a, b;
    rin >> a >> a >> b >> b;

    rep(i,1,3) {
        rep(j,1,3) {
            rep(k,1,3) {
                c[i + j + k]++;
            }
        }
    }

    mmst(mem, -1);

    ll r1 = f(a, b, 21, 21, 1, 1);
    ll r2 = f(a, b, 21, 21, 1, 0);

    cout << max(r1, r2) << endl;
}

int main() {
    freopen("21.in", "r", stdin);
    solve();
    return 0;
}