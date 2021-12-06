#include "../everything.hpp"

int cal(vector<int> &a) {
    int cnt = 0;
    For(i, a.size()) if (i > 0 && a[i] > a[i - 1]) cnt++;
    return cnt;
}

vector<int> a;
vector<int> b;
void solve() {
    read_vec(a);
    For(i, a.size()) {
        if (i >= 2) b.push_back(a[i] + a[i - 1] + a[i - 2]);
    }
    cout << cal(b) << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    solve();
    return 0;
}