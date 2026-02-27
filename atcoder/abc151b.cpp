#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k, m; cin >> n >> k >> m;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int a; cin >> a; sum += a;
    }
    int need = max(0, n * m - sum);
    if (need <= k) cout << need << endl;
    else cout << -1 << endl;
    return 0;
}
