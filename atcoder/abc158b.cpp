#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long cycle = n / (a + b);
    long long rem = n % (a + b);
    cout << cycle * a + min(rem, a) << endl;
    return 0;
}
