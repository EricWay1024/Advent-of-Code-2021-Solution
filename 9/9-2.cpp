#include "../everything.hpp"

int n, m;
vector<string> game;
vector<vector<int>> vis;
int a[N6];

const int d[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
bool is_legal(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y, int c) {
    vis[x][y] = c;
    For(i, 4) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (!is_legal(nx, ny)) continue;
        if (game[nx][ny] == '9' || vis[nx][ny]) continue;
        dfs(nx, ny, c);
    }
}

void solve() {
    string s; 
    n = 0, m = 0;
    while (cin >> s) {
        game.push_back(s);
        m = s.size();
        vis.push_back(vector(m, 0));
    }
    n = game.size();

    int c = 0;
    For(x, n) {
        For(y, m) {
            if (!vis[x][y] && game[x][y] != '9') dfs(x, y, ++c);
        }
    }

    For(x, n) {
        For(y, m) {
            a[vis[x][y]]++;
        }
    }
    sort(a + 1, a + c + 1);
    ll ans = 1;
    rep(i,0,2) ans *= a[c - i];
    cout << ans << endl;
}

int main() {
    freopen("9.in", "r", stdin);
    solve();
    return 0;
}