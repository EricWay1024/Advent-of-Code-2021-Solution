#include "../everything.hpp"
#include "./24-input.cpp"

map<pair<int, int>, vector<int>> mem;
map<pair<int, int>, int> vis;

vector<int> dfs(int cur, int z0) {
    if (vis[make_pair(cur, z0)]) return mem[make_pair(cur, z0)];
    vis[make_pair(cur, z0)] = 1;
    if (cur == 13) {
        vector<int> res;
        rev(w, 9, 1) if (functions[cur](w, z0) == 0) {
            res.push_back(w);
            break;
        }
        return mem[make_pair(cur, z0)] = res;
    }

    rev(w, 9, 1) {
        int z1 = functions[cur](w, z0);
        if (z1 < 0) continue;
        vector<int> res = dfs(cur + 1, z1);
        if (res.size()) {
            res.push_back(w);
            return mem[make_pair(cur, z0)] = res;
        }
    }

    return mem[make_pair(cur, z0)];
}

int check(vector<int> res) {
    int z = 0;
    For(i, 14) {
        z = functions[i](res[i], z);
    }
    return z;
}

void solve() {
    auto res = dfs(0, 0);
    reverse(res.begin(), res.end());
    // logs(check(res));
    for (auto i: res) cout << i;
    cout << endl;
}

int main() {
    freopen("24.in", "r", stdin);
    solve();
    return 0;
}