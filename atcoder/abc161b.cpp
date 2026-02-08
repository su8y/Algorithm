#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    int count = 0;
    for (int x : a) {
        if (x * 4 * m >= total) count++;
    }
    cout << (count >= m ? "Yes" : "No") << endl;
    return 0;
}
