#include "../everything.hpp"
vector<string> game;
int n, m;

bool move_east() {
    vector<pair<int, int>> v;
    For(i, n) {
        For(j, m) {
            if (game[i][j] == '>' && game[i][(j + 1) % m] == '.') {
                v.emplace_back(i, j);
            }
        }
    }

    for (auto [i, j]: v) {
        game[i][j] = '.';
        game[i][(j + 1) % m] = '>';
    }

    return !v.empty();
}



bool move_south() {
    vector<pair<int, int>> v;
    For(i, n) {
        For(j, m) {
            if (game[i][j] == 'v' && game[(i + 1) % n][j] == '.') {
                v.emplace_back(i, j);
            }
        }
    }

    for (auto [i, j]: v) {
        game[i][j] = '.';
        game[(i + 1) % n][j] = 'v';
    }
    
    return !v.empty();
}

void solve() {
    string s;
    while (cin >> s) game.push_back(s);
    n = game.size();
    m = game[0].size();

    int cnt = 0;

    while (1) {
        bool k = 0;
        k |= move_east();
        k |= move_south();
        cnt++;
        if (!k) {
            break;
        }
    }

    cout << cnt << endl;
}

int main() {
    freopen("25.in", "r", stdin);
    solve();
    return 0;
}