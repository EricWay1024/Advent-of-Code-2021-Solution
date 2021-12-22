#include "../everything.hpp"
const int N = 841;
short on[N][N][N];
vector<int> xs;
vector<int> ys;
vector<int> zs;
vector<tuple<bool, int, int, int, int, int, int>> commands;

void unique_fy(vector<int> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

int find_index(int t, vector<int> &ts) {
    return lower_bound(ts.begin(), ts.end(), t) - ts.begin();
}

void solve() {

    whileneof {
        char o; cin >> o >> o;
        int xa, xb, ya, yb, za, zb;
        rin >> xa >> xb >> ya >> yb >> za >> zb;
        xs.push_back(xa);
        xs.push_back(xb + 1);
        ys.push_back(ya);
        ys.push_back(yb + 1);
        zs.push_back(za);
        zs.push_back(zb + 1);
        commands.emplace_back(o == 'n', xa, xb, ya, yb, za, zb);
    }

    unique_fy(xs);
    unique_fy(ys);
    unique_fy(zs);

    for (auto [o, xa, xb, ya, yb, za, zb]: commands) {
        int x1 = find_index(xa, xs);
        int x2 = find_index(xb + 1, xs);
        int y1 = find_index(ya, ys);
        int y2 = find_index(yb + 1, ys);
        int z1 = find_index(za, zs);
        int z2 = find_index(zb + 1, zs);

        rep(i,x1,x2-1) rep(j,y1,y2-1) rep(k,z1,z2-1) {
            on[i][j][k] = o;
        }
    }

    ll res = 0;
    For(i,xs.size()-1) {
        For(j,ys.size()-1) {
            For(k,zs.size()-1) {
                if (on[i][j][k]) {
                    res += (ll)(xs[i+1]-xs[i]) * (ys[j+1]-ys[j]) * (zs[k+1]-zs[k]);
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    freopen("22.in", "r", stdin);
    solve();
    return 0;
}