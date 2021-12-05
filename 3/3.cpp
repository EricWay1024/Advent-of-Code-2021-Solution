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
    int cnt[N3][2];
    int n;

    void solve() {
        string s;
        while (cin >> s) {
            n = s.size();
            For(i, n) {
                short c = s[i] - '0';
                cnt[i][c]++;
            }
        }
        int a = 0;
        int b = 0;
        For(i, n) {
            a <<= 1;
            a |= (cnt[i][1] > cnt[i][0]);

            b <<= 1;
            b |= (cnt[i][0] > cnt[i][1]);
        }

        cout << a * b << endl;
    }
}

namespace two {
    int n;

    vector<string> filter(vector<string> &v, int k, int mode) {
        vector<string> u;
        int c[2];
        c[1] = c[0] = 0;
        for (auto &s : v) {
            c[s[k] - '0']++;
        }

        int keep = mode ? (c[1] >= c[0] ? 1 : 0) : (c[0] <= c[1] ? 0 : 1);
        for (auto &s : v) {
            if (s[k] - '0' == keep) u.push_back(s);
        }

        return u;
    }


    int cal(vector<string> v, int mode) {
        int k = 0;
        while (v.size() > 1) {
            v = filter(v, k, mode);
            k++;
        }
        auto s = v[0];
        int t = 0;
        for (char c : s) {
            t <<= 1;
            t += c - '0';
        }
        return t;
    }

    void solve() {
        string s;
        vector<string> v;
        while (cin >> s) {
            n = s.size();
            v.push_back(s);
        }
        int a = cal(v, 1);
        int b = cal(v, 0);
        cout << a * b << endl;
    }
}


int main() {
    freopen("3.in", "r", stdin);
    // one::solve();
    two::solve();

    return 0;
}