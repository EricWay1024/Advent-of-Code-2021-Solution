#include "../everything.hpp"

ll x, y, vx, vy;
ll xs, xt, ys, yt;
void step() {
    x += vx;
    y += vy;
    if (vx > 0) vx--;
    else if (vx < 0) vx++;
    vy--;
}

void solve() {
    rin >> xs >> xt >> ys >> yt;

    ll res = 0;
    int N = 1e3;
    rep(i,1,N) {
        rep(j,-N,N) {
            x = y = 0;
            vx = i; vy = j;

            ll hght = 0;
            ll flag = 0;
            while (1) {
                step();
                hght = max(hght, y);
                if (xs <= x && x <= xt && ys <= y && y <= yt) {
                    flag = 1;
                    break;
                }
                if (x > xt) break;
                if (vx == 0 && y < ys) break;
            }

            if (flag) res = max(res, hght);
        }
    }

    cout << res << endl;
}

int main() {
    freopen("17.in", "r", stdin);
    solve();
    return 0;
}