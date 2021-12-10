#include "../everything.hpp"

map<char, char> mch;
map<char, bool> lft;
map<char, int> pnt;
stack<char> st;

ll cal(string &s) {
    while (st.size()) st.pop();
    for (char c: s) {
        if (lft[c]) {
            st.push(c);
        } else {
            if (st.empty()) return 0;
            char t = st.top(); st.pop();
            if (t != mch[c]) {
                return pnt[c];
            } 
        }
    }
    return 0;
}

void solve() {
    mch['['] = ']';
    mch['('] = ')';
    mch['<'] = '>';
    mch['{'] = '}'; 

    mch[']'] = '[';
    mch[')'] = '(';
    mch['>'] = '<';
    mch['}'] = '{';

    lft['['] = 1;
    lft['('] = 1;
    lft['<'] = 1;
    lft['{'] = 1;


    pnt[')'] = 3;
    pnt[']'] = 57;
    pnt['}'] = 1197;
    pnt['>'] = 25137; 

    string s;
    ll res = 0;
    while (cin >> s) {
        res += cal(s);
    }
    cout << res << endl;
}

int main() {
    freopen("10.in", "r", stdin);
    solve();
    return 0;
}