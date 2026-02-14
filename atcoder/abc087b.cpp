#include <iostream>
using namespace std;

int main() {
    int a, b, c, x; cin >> a >> b >> c >> x;
    int count = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            int rem = x - 500 * i - 100 * j;
            if (rem >= 0 && rem % 50 == 0 && rem / 50 <= c) count++;
        }
    }
    cout << count << endl;
    return 0;
}
