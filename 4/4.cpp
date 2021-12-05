#include <bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
#ifdef D
    void dbg() {cerr << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cerr << a << ' '; dbg(x...);}
    #define logs(x...) {cerr << #x << " -> "; dbg(x);}
#else
    #define logs(...) {}
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll; typedef long double ld; typedef double db;
typedef pair<ll,ll> pll; typedef pair<int,int> pii; typedef vector<ll> vll; typedef vector<int> vint;
template <typename T> vector<T>& operator<< (vector<T> &v, T &x) { v.emplace_back(x); return v; }
struct MyIn { 
    template <typename T> MyIn& operator>> (T &x) { x=0;bool s=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')s=1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}if(s)x=-x;return (*this); } 
} rin;
const int N1 = 11; const int N2 = 112; const int N3 = 1123; const int N4 = 11234; const int N5 = 112345; const int N6 = 1123456; const int N7 = 11234567;


template <typename T>
void read_vec(vector<T> &a) {
    T t;
    while (cin >> t) a.emplace_back(t);
}

const int N = 100; // number of numbers drawn
const int M = 100; // number of boards

namespace one {
    int a[N2];
    int b[N2][N1][N1];
    int mark[N2][N1][N1];
    int col[N2][N1];
    int row[N2][N1];

    vector< tuple<int, int, int> > mp[N2];
    void solve() {
        rep(i,1,N) rin >> a[i];

        rep(i,1,M) rep(j,1,5) rep(k,1,5) {
            rin >> b[i][j][k]; 
            mp[b[i][j][k]].push_back(make_tuple(i, j, k)); 
        }

        rep(l,1,N) {
            int u = a[l];
            for (auto &[i, j, k] : mp[u]) {
                if (!mark[i][j][k]) {
                    mark[i][j][k] = 1;
                    col[i][j]++;
                    row[i][k]++;

                    if (col[i][j] == 5 || row[i][k] == 5) {
                        ll res = 0;
                        rep(x,1,5) rep(y,1,5) if (!mark[i][x][y]) res += b[i][x][y];
                        res *= u;
                        cout << res << endl;
                        return;
                    }
                    
                }
            }
        }
    }
}

namespace two {
    int a[N2];
    int b[N2][N1][N1];
    int mark[N2][N1][N1];
    int col[N2][N1];
    int row[N2][N1];
    set<int> win;
    vector< tuple<int, int, int> > mp[N2];

    void solve() {
        rep(i,1,N) rin >> a[i];

        rep(i,1,M) rep(j,1,5) rep(k,1,5) {
            rin >> b[i][j][k]; 
            mp[b[i][j][k]].push_back(make_tuple(i, j, k)); 
        }

        rep(l,1,N) {
            int u = a[l];
            for (auto &[i, j, k] : mp[u]) {
                if (!mark[i][j][k]) {
                    mark[i][j][k] = 1;
                    col[i][j]++;
                    row[i][k]++;

                    if (col[i][j] == 5 || row[i][k] == 5) {
                        win.insert(i);
                        if (win.size() == M) {
                            ll res = 0;
                            rep(x,1,5) rep(y,1,5) if (!mark[i][x][y]) res += b[i][x][y];
                            res *= u;
                            cout << res << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
}
int main() {
    freopen("4.in", "r", stdin);
    // one::solve();
    two::solve();


    return 0;
}