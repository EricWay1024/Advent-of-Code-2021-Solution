#include "../everything.hpp"

map<char, string> dict;

string s;
string t;

int cur;

#define rd() (t[cur++] - '0')
#define rn(x, n) For(_, n) { x <<= 1; x += rd(); }

int res = 0;

void read_p() {
    int V = 0;
    rn(V, 3);

    res += V;

    int T = 0;
    rn(T, 3);

    if (T == 4) {
        while (true) {
            int flag = rd();
            int A = 0;
            rn(A, 4);
            if (!flag) break;
        }
    }

    else {
        int I = rd();
        if (I) {
            int L = 0;
            rn(L, 11);
            For(i, L) {
                read_p();
            }
        }

        else {
            int L = 0;
            rn(L, 15);
            int x = cur + L;
            while (cur < x) {
                read_p();
            }
        }
    }
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

    read_p();
    cout << res << endl;

}

int main() {
    freopen("16.in", "r", stdin);
    solve();
    return 0;
}