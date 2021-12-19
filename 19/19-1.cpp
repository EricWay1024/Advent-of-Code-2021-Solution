#include "../everything.hpp"
using tiii = tuple<int, int, int>;
using viii = vector<tuple<int, int, int>>;


viii intersection(viii &v1, viii &v2){
    viii v3;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::set_intersection(v1.begin(),v1.end(),
                          v2.begin(),v2.end(),
                          back_inserter(v3));
    return v3;
}

viii union_(viii &v1, viii &v2){
    viii v3;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::set_union(v1.begin(),v1.end(),
                          v2.begin(),v2.end(),
                          back_inserter(v3));
    return v3;
}

vector<viii> trsfm(viii vs) {
    vector<viii> res;

    int a[3] = {0, 1, 2};

    do {
        For(s, 8) {
            viii u;
            for (auto p: vs) {
                int b[3];
                b[0] = get<0>(p);
                b[1] = get<1>(p);
                b[2] = get<2>(p);
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
    set<tiii> diff;
    for (auto [vx, vy, vz]: vs) {
        for (auto [ux, uy, uz]: us) {
            diff.insert(make_tuple(ux-vx, uy-vy, uz-vz));
        }
    }

    for (auto [dx, dy, dz]: diff) {
        viii nvs;
        for (auto [x, y, z]: vs) {
            nvs.emplace_back(x+dx, y+dy, z+dz);
        }
        auto res = intersection(nvs, us);
        if (res.size() >= 12) {
            return union_(nvs, us);
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
        if (s[0] == '-' && s[1] == '-' && s[2] == '-') {
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
    // freopen("19.test", "r", stdin);
    solve();
    return 0;
}