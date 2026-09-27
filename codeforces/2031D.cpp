// codeforces 2031D
#include <iostream>
#include <vector>

using namespace std;

// 정답은 무조건 단조증가임. 증가지점 찾아야 함. (귀류법으로 증명 가능)
void solve() {
    int n, M = 1, m;
    cin >> n;

    vector<int> a(n), acc_max(n), rev_acc_min(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        M = max(a[i], M);
        acc_max[i] = M;
    }

    m = a[n - 1];
    for (int i = n - 1; i > 0; i--) {
        m = min(a[i], m);
        if (m >= acc_max[i - 1])
            M = acc_max[i - 1];
        else
            acc_max[i - 1] = M;
    }

    for (int i = 0; i < n; i++) {
        cout << acc_max[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}