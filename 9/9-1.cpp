#include "../everything.hpp"

int n, m;
vector<string> game;

const int d[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
bool is_legal(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool is_low(int x, int y) {
    For(i, 4) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (!is_legal(nx, ny)) continue;
        if (game[x][y] >= game[nx][ny]) return 0;
    }
    return 1;
}

void solve() {
    string s; 
    n = 0, m = 0;
    while (cin >> s) {
        game.push_back(s);
        m = s.size();
    }
    n = game.size();

    ll cnt = 0;
    For(x, n) {
        For(y, m) {
            if (is_low(x, y)) {
                cnt += game[x][y] - '0' + 1;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    freopen("9.in", "r", stdin);
    solve();
    return 0;
}