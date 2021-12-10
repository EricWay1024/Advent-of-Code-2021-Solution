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
            if (st.empty()) return -1;
            char t = st.top(); st.pop();
            if (t != mch[c]) {
                return -1;
            } 
        }
    }
    ll res = 0;
    while (st.size()) {
        char t = st.top(); st.pop();
        res = res * 5 + pnt[mch[t]];
    }
    return res;
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


    pnt[')'] = 1;
    pnt[']'] = 2;
    pnt['}'] = 3;
    pnt['>'] = 4; 

    string s;
    vector<ll> v;
    while (cin >> s) {
        ll res = cal(s);
        if (res == -1) continue;
        v.push_back(res);
    }
    sort(v.begin(), v.end());
    cout << v[v.size() / 2] << endl;
}

int main() {
    freopen("10.in", "r", stdin);
    solve();
    return 0;
}