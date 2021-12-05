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


int cal(vector<int> &a) {
    int cnt = 0;
    For(i, a.size()) if (i > 0 && a[i] > a[i - 1]) cnt++;
    return cnt;
}

template <typename T>
void read_vec(vector<T> &a) {
    T t;
    while (cin >> t) a.emplace_back(t);
}

namespace one {
    vector<int> a;
    void solve() {
        read_vec(a);
        cout << cal(a) << endl;
    }
}

namespace two {
    vector<int> a;
    vector<int> b;
    void solve() {
        read_vec(a);
        For(i, a.size()) {
            if (i >= 2) b.push_back(a[i] + a[i - 1] + a[i - 2]);
        }
        cout << cal(b) << endl;
    }
}

int main() {
    freopen("1.in", "r", stdin);

    // one::solve();
    two::solve();

    return 0;
}