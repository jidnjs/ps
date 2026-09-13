// codeforces 2078D
#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mult[30][2], add[30] = {};
    long long dp[31][2] = {};
    for (int i = 0; i < n; i++) {
        char op1, op2;
        int a1, a2;
        cin >> op1 >> a1 >> op2 >> a2;
        if (op1 == 'x') {
            mult[i][0] = a1;
        } else {
            mult[i][0] = 1;
            add[i] += a1;
        }
        
        if (op2 == 'x') {
            mult[i][1] = a2;
        } else {
            mult[i][1] = 1;
            add[i] += a2;
        }
    }
    
    dp[n][0] = 1;
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(dp[i + 1][0] * mult[i][0], dp[i + 1][0] + dp[i + 1][1] * (mult[i][0] - 1));
        dp[i][1] = max(dp[i + 1][1] * mult[i][1], dp[i + 1][1] + dp[i + 1][0] * (mult[i][1] - 1));
    }
    
    long long left = 1, right = 1;
    for (int i = 0; i < n; i++) {
        long long n = add[i] + left * (mult[i][0] - 1) + right * (mult[i][1] - 1);
        if (dp[i + 1][0] > dp[i + 1][1]) {
            left += n;
        } else {
            right += n;
        }
    }
    cout << left + right << "\n";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
        solve();
}
