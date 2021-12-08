#include "../everything.hpp"

void solve() {
    int m = 0;
    while (1) {
        string s;
        rep(i,1,10) cin >> s;
        cin >> s;
        rep(i,1,4) {
            cin >> s;
            auto sz = s.size();
            if (sz == 7 || sz == 3 || sz == 2 || sz == 4) m++;
        }
        cin >> ws;
        if (cin.peek() == -1) break;
    }
    cout << m << endl;
}

int main() {
    freopen("8.in", "r", stdin);
    solve();
    return 0;
}