#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while (k--) {
            int a; cin >> a;
            cnt[a]++;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) if (cnt[i] == n) res++;
    cout << res << endl;
    return 0;
}
