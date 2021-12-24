#include "../everything.hpp"

void compile() {
    int cnt = 0;
    whileneof {
        string op; cin >> op;
        if (op == "inp") {
            char c; cin >> c;
            if (cnt) puts("\treturn z;\n}\n");
            printf("int f%d(int w, int z) {\n\tint x = 0, y = 0;\n", ++cnt, c);
        } else {
            string t, r;
            cin >> t >> r;
            if (op == "mul") {
                cout << "\t" << t << " *= " << r << ";\n";
            } else if (op == "add") {
                cout << "\t" << t << " += " << r << ";\n";
            } else if (op == "div") {
                cout << "\t" << t << " /= " << r << ";\n";
            } else if (op == "mod") {
                cout << "\t" << t << " %= " << r << ";\n";
            } else if (op == "eql") {
                cout << "\t" << t << " = (" << t << " == " << r << ");\n";
            }
        }
    }

    puts("\treturn z;\n}\n");

    puts("typedef int (*IntFunction) (int w, int z);");
    puts("IntFunction functions[] = {");
    puts("\tf1,");

    rep(i,1,14) printf("\tf%d%c\n", i, i == 14 ? ' ' : ',');
    puts("};");
}


int main() {
    freopen("24.in", "r", stdin);
    freopen("24-input.cpp", "w", stdout);
    compile();
    return 0;
}