#include <bits/stdc++.h>
using namespace std;
#define rep(i, from, to) for (int i = (int)(from); i <= (int)(to); ++i)
#define rev(i, from, to) for (int i = (int)(from); i >= (int)(to); --i)
#define For(i, to) for (int i = 0; i < (int)(to); ++i)
#define endl '\n'
#define coutP(i) cout << fixed << setprecision(i)
#define whileneof while((cin >> ws) && (~cin.peek()))
void dbg()
{
    cerr << "\n";
}
template <typename T, typename... A>
void dbg(T a, A... x)
{
    cerr << a << ' ';
    dbg(x...);
}
#define logs(x...)            \
    {                         \
        cerr << #x << " -> "; \
        dbg(x);               \
    }
#define mmst(a, x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vint;
template <typename T>
vector<T> &operator<<(vector<T> &v, T &x)
{
    v.emplace_back(x);
    return v;
}
struct MyIn
{
    template <typename T>
    MyIn &operator>>(T &x)
    {
        x = 0;
        bool s = 0;
        char c = getchar();
        while (c > '9' || c < '0')
        {
            if (c == '-')
                s = 1;
            c = getchar();
        }
        while (c >= '0' && c <= '9')
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        if (s)
            x = -x;
        return (*this);
    }
} rin;
const int N1 = 11;
const int N2 = 112;
const int N3 = 1123;
const int N4 = 11234;
const int N5 = 112345;
const int N6 = 1123456;
const int N7 = 11234567;
template <typename T>
void read_vec(vector<T> &a)
{
    T t;
    while (cin >> t)
        a.emplace_back(t);
}
vector<string> split(string &str, char delim)
{   
    vector<string> out;
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
    return out;
}
vector<ll> map_to_ll(vector<string> v) {
    vector<ll> u;
    for (auto s: v) u.push_back(stoll(s));
    return u;
}
template<typename T>
void output_vec(vector<T> &v, char delim='\n') {
    for (auto x: v) {
        cout << x << delim;
    }
}