#include <iostream>
using namespace std;

int digit_sum(int n) {
    int s = 0;
    while (n > 0) { s += n % 10; n /= 10; }
    return s;
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int d = digit_sum(i);
        if (a <= d && d <= b) res += i;
    }
    cout << res << endl;
    return 0;
}
