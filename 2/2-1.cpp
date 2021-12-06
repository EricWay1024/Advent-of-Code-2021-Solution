#include "../everything.hpp"

void solve() {
    string s; int t;
    int x = 0; int y = 0;
    while (cin >> s >> t) {
        if (s[0] == 'f') x += t;
        if (s[0] == 'd') y += t;
        if (s[0] == 'u') y -= t;
    }

    cout << x * y << endl;
}



int main() {
    freopen("2.in", "r", stdin);
    solve();
    return 0;
}