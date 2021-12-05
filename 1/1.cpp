#include "../everything.hpp"

int cal(vector<int> &a) {
    int cnt = 0;
    For(i, a.size()) if (i > 0 && a[i] > a[i - 1]) cnt++;
    return cnt;
}

namespace one {
    vector<int> a;
    void solve() {
        read_vec(a);
        cout << cal(a) << endl;
    }
}

namespace two {
    vector<int> a;
    vector<int> b;
    void solve() {
        read_vec(a);
        For(i, a.size()) {
            if (i >= 2) b.push_back(a[i] + a[i - 1] + a[i - 2]);
        }
        cout << cal(b) << endl;
    }
}

int main() {
    freopen("1.in", "r", stdin);

    // one::solve();
    two::solve();

    return 0;
}