#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, l; cin >> n >> l;
    int total = 0, min_abs = 1e9, eat = 0;
    for (int i = 1; i <= n; i++) {
        int flavor = l + i - 1;
        total += flavor;
        if (abs(flavor) < min_abs) {
            min_abs = abs(flavor);
            eat = flavor;
        }
    }
    cout << total - eat << endl;
    return 0;
}
