#include "../everything.hpp"

map<char, string> dict;

string s;
string t;

int cur;

int rn(int n) {
    int x = 0;
    For(_, n) { x <<= 1; x += (t[cur++] - '0'); }
    return x;
}

int res = 0;

void read_p() {
    int V = rn(3);
    res += V;
    int T = rn(3);

    if (T == 4) {
        while (true) {
            int flag = rn(1);
            int A = rn(4);
            if (!flag) break;
        }
    }

    else {
        int I = rn(1);
        if (I) {
            int L = rn(11);
            For(i, L) {
                read_p();
            }
        }

        else {
            int L = rn(15);
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