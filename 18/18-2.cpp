// compiled and run by 18-2.py
#include "../everything.hpp"


struct Tree {
    struct Node {
        int l, r;
        int fa;
        ll val;
    } a[N6];
    int tot, root;

    int read() {
        int x = ++tot;

        char o;
        if (cin >> ws && cin.peek() == '[') {
            cin >> o;
            a[x].l = read();
            cin >> o;
            a[x].r = read();
            cin >> o;
            a[a[x].l].fa = x;
            a[a[x].r].fa = x;
        } else {
            cin >> (a[x].val);
        }

        return x;
    }

    // void output(int u, int mode=0) {
    //     if (a[u].l) {
    //         if (mode) cout << u;
    //         cout << '[';
    //         output(a[u].l);
    //         cout << ',';
    //         output(a[u].r);
    //         cout << ']';
    //     } else {
    //         cout << a[u].val;
    //         if (mode) cout << ' ' << u;
    //     }
    // }

    int getNext(int u) {
        while (1) {
            if (u == 0) return 0;
            if (a[a[u].fa].r == u) u = a[u].fa;
            else {
                u = a[u].fa;
                break;
            }
        }
        u = a[u].r;
        while (1) {
            if (a[u].l) u = a[u].l;
            else break;
        }
        return u;
    }

    int getPrev(int u) {
        while (1) {
            if (u == 0) return 0;
            if (a[a[u].fa].l == u) u = a[u].fa;
            else {
                u = a[u].fa;
                break;
            }
        }
        u = a[u].l;
        while (1) {
            if (a[u].r) u = a[u].r;
            else break;
        }
        return u;
    }


    void explode(int u) {
        int v;
        v = getPrev(u);
        if (v) a[v].val += a[a[u].l].val;
        v = getNext(u);
        if (v) a[v].val += a[a[u].r].val;

        a[a[u].l].fa = 0;
        a[a[u].r].fa = 0;
        a[u].l = a[u].r = 0;
        a[u].val = 0;
    }

    bool try_explode(int u, int d) {
        if (d == 5 && a[u].l) {
            explode(u);
            return 1;
        } else {
            if (a[u].l) {
                bool k;
                k = try_explode(a[u].l, d + 1);
                if (k) return 1;
                k = try_explode(a[u].r, d + 1);
                if (k) return 1;
            }
        }
        return 0;
    }

    bool split(int u) {
        if (a[u].l) {
            bool k;
            k = split(a[u].l);
            if (k) return 1; 
            k = split(a[u].r);
            if (k) return 1;

        } else {
            if (a[u].val >= 10) {
                a[u].l = ++tot;
                a[a[u].l].fa = u;
                a[a[u].l].val = a[u].val / 2;

                a[u].r = ++tot;
                a[a[u].r].fa = u;
                a[a[u].r].val = (a[u].val + 1) / 2;

                a[u].val = 0;
                return 1;
            }
        }

        return 0;
    }


    void maintain(int r) {
        while (1) {
            bool k;
            k = try_explode(r, 1);
            if (k) continue;
            k = split(r);
            if (k) continue;
            break;
        }
    }

    ll calc(int u) {
        if (a[u].l) {
            return calc(a[u].l) * 3 + calc(a[u].r) * 2;
        } else return a[u].val;
    }


    void work() {
        int r1, r2, u;
        r1 = read();

        whileneof {
            r2 = read();
            u = ++tot;

            a[u].l = r1;
            a[u].r = r2;
            a[r1].fa = u;
            a[r2].fa = u;
            maintain(u);

            r1 = u;
        }

        cout << calc(u) << endl;
    }


} t1;


void solve() {
    t1.work();
}

int main() {
    freopen("18-2.in", "r", stdin);
    freopen("18-2.out", "w", stdout);
    solve();
    return 0;
}