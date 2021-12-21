#include "../everything.hpp"

int dice = 1;
int cnt = 0;
int get_dice() {
    int res = dice;
    dice++;
    if (dice == 101) dice = 1;
    cnt++;
    return res;
}

int get_player_step() {
    return get_dice() + get_dice() + get_dice();
}


void solve() {
    int a, b;
    rin >> a >> a >> b >> b;
    int x = 0, y = 0;
    while (1) {
        int p1 = get_player_step();
        a = (a + p1 + 9) % 10 + 1;
        x += a;

        if (x >= 1000) {
            cout << y * cnt << endl;
            break;
        }

        int p2 = get_player_step();
        b = (b + p2 + 9) % 10 + 1;
        y += b;

        if (y >= 1000) {
            cout << x * cnt << endl;
            break;
        }
    }
}

int main() {
    freopen("21.in", "r", stdin);
    solve();
    return 0;
}