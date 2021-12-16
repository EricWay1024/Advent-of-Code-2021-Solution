#include "../everything.hpp"

map<char, string> dict;

string s;
string t;

ll cur;

#define rd() (t[cur++] - '0')
#define rn(x, n) For(_, n) { x <<= 1; x += rd(); }

ll read_p() {
    ll V = 0;
    rn(V, 3);

    ll T = 0;
    rn(T, 3);

    if (T == 4) {
        ll B = 0;
        while (true) {
            ll flag = rd();
            ll A = 0;
            rn(A, 4);
            B <<= 4;
            B += A;
            if (!flag) break;
        }
        return B;
    }

    else {
        ll I = rd();
        vector<ll> v;
        if (I) {
            ll L = 0;
            rn(L, 11);
            For(i, L) {
                v.push_back(read_p());
            }
        }
        
        else {
            ll L = 0;
            rn(L, 15);
            ll x = cur + L;
            while (cur < x) {
                v.push_back(read_p());
            }
        }

        if (T == 0) {
            ll u = 0;
            for (auto x: v) u += x;
            return u;
        } else if (T == 1) {
            ll u = 1;
            for (auto x: v) u *= x;
            return u;
        } else if (T == 2) {
            ll u = v[0];
            for (auto x: v) u = min(u, x);
            return u;
        } else if (T == 3) {
            ll u = v[0];
            for (auto x: v) u = max(u, x);
            return u;
        } else if (T == 5) {
            return v[0] > v[1];
        } else if (T == 6) {
            return v[0] < v[1];
        } else if (T == 7) {
            return v[0] == v[1];
        }
    }

    return 0;
}

void solve() {
    dict['0'] = "0000";
    dict['1'] = "0001";
    dict['2'] = "0010";
    dict['3'] = "0011";
    dict['4'] = "0100";
    dict['5'] = "0101";
    dict['6'] = "0110";
    dict['7'] = "0111";
    dict['8'] = "1000";
    dict['9'] = "1001";
    dict['A'] = "1010";
    dict['B'] = "1011";
    dict['C'] = "1100";
    dict['D'] = "1101";
    dict['E'] = "1110";
    dict['F'] = "1111";

    cin >> s;
    for (char c: s) {
        t.append(dict[c]);
    }

    ll res = read_p();
    cout << res << endl;
}

int main() {
    freopen("16.in", "r", stdin);
    solve();
    return 0;
}