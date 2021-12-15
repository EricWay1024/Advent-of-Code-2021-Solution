#include "../everything.hpp"

vector<string> game;
vector<vector<ll>> vis;
queue<pii> q;

const int d[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
int n, m;
void solve() {
    string s;
    while (cin >> s) {
        game.push_back(s);
        m = s.size();
        vis.push_back(vector<ll>(m, INT64_MAX));
    }
    n = game.size();

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
    freopen("15.test", "r", stdin);
    solve();
    return 0;
}