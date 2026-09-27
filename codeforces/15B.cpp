// codeforces 15B
#include <iostream>

using namespace std;

void solve() {
    long long n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    int x = abs(x1 - x2), y = abs(y1 - y2);
    long long w = n - x, h = m - y;
    // n - 2x = 2w - n, bitshift쓰면 20% 빨라짐
    long long ans = n * m - ((w << 1) * h) + max(0LL, n - (x << 1)) * max(0LL, m - (y << 1)); 
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) 
        solve();
}