#include "../everything.hpp"

namespace one {
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
}

namespace two {
    void solve() {
        string s; int t;
        int x = 0; int y = 0;
        int aim = 0;
        while (cin >> s >> t) {
            if (s[0] == 'f') x += t, y += aim * t;
            if (s[0] == 'd') aim += t;
            if (s[0] == 'u') aim -= t;
        }
        cout << x * y << endl;
    }
}

int main() {
    freopen("2.in", "r", stdin);
    // one::solve();
    two::solve();

    return 0;
}