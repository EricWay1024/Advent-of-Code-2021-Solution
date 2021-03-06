#include "../everything.hpp"

vector<string> game;
queue<pii> q;

const int d[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
int n, m;

vector<string> make_game() {
    vector<string> res(5 * n);
    For(i,5) {
        For(j,5) {
            vector<string> v(game);
            For(x,n) {
                For(y,m) {
                    v[x][y] = (v[x][y] - '0' + i + j + 8) % 9 + 1 + '0';
                }
                res[i * n + x].append(v[x]);
            }
        }
    }
    return res;
}

void solve() {
    string s;
    while (cin >> s) {
        game.push_back(s);
        m = s.size();
    }
    n = game.size();

    game = make_game();
    n *= 5;
    m *= 5;

    vector<vll> vis(n, vll(m, INT64_MAX));
    q.push(make_pair(0, 0));
    vis[0][0] = 0;
    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        For(i,4) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] <= vis[x][y] + game[nx][ny] - '0') continue;
            vis[nx][ny] = vis[x][y] + game[nx][ny] - '0';
            q.push(make_pair(nx, ny));
        }
    }

    cout << vis[n-1][m-1] << endl;
}

int main() {
    freopen("15.in", "r", stdin);
    solve();
    return 0;
}