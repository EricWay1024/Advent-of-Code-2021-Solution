#include "../everything.hpp"

const int T = 2;
const int M = T + 10;
char out = '.';
int n, m;
string s;

char getter(vector<string> &v, int i, int j) {
    if (0 <= i && i < n && 0 <= j && j < m) return v[i][j];
    else return out;
}

vector<string> convert(vector<string> &v) {
    vector<string> res(v);
    For(i, n) {
        For(j, m) {
            int state = 0;
            rep(x, -1, 1) {
                rep(y, -1, 1) {
                    state <<= 1;
                    state |= (getter(v, i + x, j + y) == '#');
                }
            }
            res[i][j] = s[state];
        }
    }
    if (out == '.') out = s[0];
    else out = s[(1 << 9) - 1];
    return res;
}

int count(vector<string> &v) {
    int k = 0;
    For(i, n) For(j, m) k += (v[i][j] == '#');
    return k;
}

void solve() {
    cin >> s;
    vector<string> res;

    string margin = "";
    For(i, M) margin.push_back('.');
    whileneof {
        string t; cin >> t;
        string r(margin);
        r.append(t);
        r.append(margin);
        m = r.size();
        res.push_back(r);
    }
    margin.clear();
    For(i, m) margin.push_back('.');
    For(i, M) res.insert(res.begin(), margin);
    For(i, M) res.push_back(margin);
    n = res.size();

    For(_, T) res = convert(res);
    cout << count(res) << endl;
}

int main() {
    freopen("20.in", "r", stdin);
    solve();
    return 0;
}