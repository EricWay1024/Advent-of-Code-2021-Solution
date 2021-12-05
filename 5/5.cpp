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


namespace one {
    int game[N3][N3];

    void solve() {
        int a, b, x, y;
        char o;
        while (cin >> a >> o >> b >> o >> o >> x >> o >> y) {
            if (a == x) {
                rep(i,min(b,y),max(b,y)) game[a][i]++;
            } else if (b == y) {
                rep(i,min(a,x),max(a,x)) game[i][b]++;
            }
        }
        int cnt = 0;
        rep(i,0,1000) rep(j,0,1000) if (game[i][j] >= 2) cnt++;
        cout << cnt << endl;
    }

}


namespace two {
    int game[N3][N3];

    void solve() {
        int a, b, x, y;
        char o;
        while (cin >> a >> o >> b >> o >> o >> x >> o >> y) {
            if (a == x) {
                rep(i,min(b,y),max(b,y)) game[a][i]++;
            } else if (b == y) {
                rep(i,min(a,x),max(a,x)) game[i][b]++;
            } else if (y - b == x - a) {
                int k = abs(y - b);
                rep(i,0,k) game[min(a, x) + i][min(b, y) + i]++;
            } else if (y - b == a - x) {
                int k = abs(y - b);
                rep(i,0,k) game[min(a, x) + i][max(b, y) - i]++;
            }
        }

        int cnt = 0;
        rep(i,0,1000) rep(j,0,1000) if (game[i][j] >= 2) cnt++;
        cout << cnt << endl;
    }

}
int main() {
    freopen("5.in", "r", stdin);
    one::solve();
    // two::solve();

    return 0;
}