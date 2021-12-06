#include "../everything.hpp"

int n;
ll b[N1];
ll c[N1];
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
    string s; cin >> s;
    auto a = map_to_ll(split(s, ','));
    for (auto i : a) b[i]++;

    rep(i,1,256) one_day();
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