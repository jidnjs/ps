// codeforces 235A
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int n, ans = 1;
    cin >> n;
    if (n <= 2) {
        ans = n;  
    } else if (n % 6 == 0) {
        ans = (n - 1) * (n - 2) * (n - 3);
    } else if (n % 2 == 0) {
        ans = n * (n - 1) * (n - 3);
    } else {
        ans = n * (n - 1) * (n - 2);
    }

    cout << ans;
    return 0;
}