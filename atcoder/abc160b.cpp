#include <iostream>
using namespace std;

int main() {
    int x; cin >> x;
    long long res = 0;
    res += (x / 500) * 1000;
    x %= 500;
    res += (x / 5) * 5;
    cout << res << endl;
    return 0;
}
