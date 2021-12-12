#include "../everything.hpp"

map<string, int> mp;
int cnt; 
map<int, bool> is_small;
vector<int> grh[100];
int vis[N3];

int add(string u) {
    if (mp[u] == 0) mp[u] = ++cnt;
    if (u != "start" && u != "end" && u[0] >= 'a' && u[0] <= 'z') {
        is_small[mp[u]] = 1;
    }
    return mp[u];
}

int res;
void dfs(int u, int k) {
    if (k >= 2) return;
    if (u == 2) {
        res++;
        return; 
    }
    for (auto v: grh[u]) {
        if (vis[v] >= 2 || v == 1) continue;
        if (is_small[v]) vis[v]++;
        dfs(v, k + (vis[v] == 2));
        if (is_small[v]) vis[v]--;
    }
}

void solve() {
    string s; 
    add("start");
    add("end");
    while (cin >> s) {
        auto p = split(s, '-');
        string u = p[0];
        string v = p[1];
        int x = add(u); 
        int y = add(v);
        grh[x].push_back(y);
        grh[y].push_back(x);
    }
    dfs(1, 0);
    cout << res << endl;
}

int main() {
    freopen("12.in", "r", stdin);
    solve();
    return 0;
}