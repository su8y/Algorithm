#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s; cin >> s;
    bool ok = true;
    if (s[0] != 'A') ok = false;
    int c_count = 0;
    for (int i = 2; i < (int)s.size() - 1; i++) if (s[i] == 'C') c_count++;
    if (c_count != 1) ok = false;
    int upper = 0;
    for (char c : s) if (isupper(c)) upper++;
    if (upper != 2) ok = false;
    cout << (ok ? "AC" : "WA") << endl;
    return 0;
}
