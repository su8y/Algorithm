#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    int res = 0, cur = 0;
    for (char c : s) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            cur++;
            res = max(res, cur);
        } else cur = 0;
    }
    cout << res << endl;
    return 0;
}
