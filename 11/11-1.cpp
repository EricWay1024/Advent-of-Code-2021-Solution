#include "../everything.hpp"

bool flash[N2][N2];
queue<pii> q;
ll cnt = 0;
const int N = 10;

void step(vector<string> &v) {
    mmst(flash, 0);

    For(i, N) {
        For(j, N) {
            v[i][j]++;
            if (v[i][j] > '9') {
                flash[i][j] = 1;
                q.push(make_pair(i, j));
            }
        }
    }

    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        rep(dx, -1, 1) {
            rep(dy, -1, 1) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx; 
                int ny = y + dy;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (flash[nx][ny]) continue;
                v[nx][ny]++;
                if (v[nx][ny] > '9') {
                    flash[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    For(i, N){
        For(j, N) {
            if (flash[i][j]) v[i][j] = '0', cnt++;
        }
    }
}

void solve() {
    vector<string> v;
    string s;
    while (cin >> s) v.push_back(s);
    rep(i,1,100) {
        step(v);
    }
    cout << cnt << endl;
}

int main() {
    freopen("11.in", "r", stdin);
    solve();
    return 0;
}