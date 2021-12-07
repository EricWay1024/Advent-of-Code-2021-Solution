#include "../everything.hpp"

ll f(ll n) {
    return (n + 1) * n / 2;
}

ll cal(vector<ll> &a, ll t) {
    ll ans = 0;
    for (auto u: a) {
        ans += f(abs(u - t));
    }
    return ans;
}
void solve() {
    string s; cin >> s;
    auto a = map_to_ll(split(s, ','));
    ll ans = INT32_MAX;
    for (auto u: a) {
        ans = min(ans, cal(a, u));
    }
    cout << ans << endl;
}

int main() {
    freopen("7.in", "r", stdin);
    solve();
    return 0;
}