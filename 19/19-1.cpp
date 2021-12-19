#include "../everything.hpp"
using tiii = tuple<int, int, int>;
using viii = vector<tuple<int, int, int>>;

vector<viii> trsfm(viii vs) {
    vector<viii> res;

    int a[3] = {0, 1, 2};
    do {
        For(s, 8) {
            viii u;
            for (auto p: vs) {
                int b[3];
                tie(b[0], b[1], b[2]) = p;
                int c[3];
                For(i, 3) {
                    if ((s >> i) & 1) c[i] = -1;
                    else c[i] = 1;
                }
                u.emplace_back(c[0] * b[a[0]], c[1] * b[a[1]], c[2] * b[a[2]]);
            }
            res.push_back(u);
        }
    } while (next_permutation(a, a + 3));

    return res;
}

viii cmpre(viii vs, viii us) {
    map<tiii, int> diff;
    for (auto [vx, vy, vz]: vs) {
        for (auto [ux, uy, uz]: us) {
            int dx = ux-vx;
            int dy = uy-vy;
            int dz = uz-vz;
            int &cnt = diff[make_tuple(dx, dy, dz)];
            cnt++;
            if (cnt == 12) {
                for (auto [x, y, z]: vs) {
                    us.emplace_back(x+dx, y+dy, z+dz);
                }
                sort(us.begin(), us.end());
                us.resize(unique(us.begin(), us.end()) - us.begin());
                return us;
            }
        }
    }
    viii emp;
    return emp;
}

viii try_add(viii us, viii vs) {
    auto vss = trsfm(vs);
    for (auto nvs: vss) {
        auto res = cmpre(nvs, us);
        if (res.size()) return res;
    }
    viii emp;
    return emp;
}

void solve() {
    vector<viii> pts;

    viii vs;
    bool first = 1;
    whileneof {
        string s; getline(cin, s);
        if (s[0] == '-' && s[1] == '-') {
            if (first) {
                first = 0;
            } else {
                pts.push_back(vs);
                vs.clear();
            }
            continue;
        }
        istringstream iss(s);
        char o;
        int x, y, z;
        iss >> x >> o >> y >> o >> z;
        vs.push_back(make_tuple(x, y, z));
    }
    pts.push_back(vs);
    vs.clear();

    while (pts.size() > 1) {
        bool flag = 0;
        For(i, pts.size()) {
            For(j, pts.size()) if (i < j) {
                auto res = try_add(pts[i], pts[j]);
                if (res.size() == 0) continue;
                // logs(res.size())
                pts.erase(pts.begin() + i);
                pts.erase(pts.begin() + j - 1);
                pts.push_back(res);
                flag = 1;
                break;
            }
            if (flag) break;
        }

    }
    
    cout << pts[0].size() << endl;
}

int main() {
    freopen("19.in", "r", stdin);
    solve();
    return 0;
}