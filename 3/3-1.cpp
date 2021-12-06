#include "../everything.hpp"

int cnt[N3][2];
int n;

void solve() {
    string s;
    while (cin >> s) {
        n = s.size();
        For(i, n) {
            short c = s[i] - '0';
            cnt[i][c]++;
        }
    }
    int a = 0;
    int b = 0;
    For(i, n) {
        a <<= 1;
        a |= (cnt[i][1] > cnt[i][0]);

        b <<= 1;
        b |= (cnt[i][0] > cnt[i][1]);
    }

    cout << a * b << endl;
}

int main() {
    freopen("3.in", "r", stdin);
    solve();
    return 0;
}