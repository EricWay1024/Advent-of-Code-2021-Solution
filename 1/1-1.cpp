#include "../everything.hpp"

int cal(vector<int> &a) {
    int cnt = 0;
    For(i, a.size()) if (i > 0 && a[i] > a[i - 1]) cnt++;
    return cnt;
}

vector<int> a;
void solve() {
    read_vec(a);
    cout << cal(a) << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    solve();
    return 0;
}