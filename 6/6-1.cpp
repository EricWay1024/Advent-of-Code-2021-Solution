#include "../everything.hpp"

int n;
int a[N3];
int b[N1];
int c[N1];
void one_day() {
    mmst(c, 0);
    c[6] = b[0];
    c[8] = b[0];
    rep(i,1,8) {
        c[i - 1] += b[i];
    }

    rep(i,0,8) b[i] = c[i];
}

void solve() {
    n = 300;
    rep(i,1,n) rin >> a[i];
    rep(i,1,n) {
        b[a[i]]++;
    }
    rep(i,1,80) one_day();
    ll ans = 0;
    rep(i,0,8) {
        ans += b[i];
    }
    cout << ans << endl;
}

int main() {
    freopen("6.in", "r", stdin);
    solve();
    return 0;
}