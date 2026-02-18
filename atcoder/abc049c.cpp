#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    string words[] = {"dream", "dreamer", "erase", "eraser"};
    reverse(s.begin(), s.end());
    for (int i = 0; i < 4; i++) reverse(words[i].begin(), words[i].end());

    bool can = true;
    for (int i = 0; i < (int)s.size(); ) {
        bool match = false;
        for (string w : words) {
            if (s.substr(i, w.size()) == w) {
                match = true;
                i += w.size();
                break;
            }
        }
        if (!match) { can = false; break; }
    }
    cout << (can ? "YES" : "NO") << endl;
    return 0;
}
