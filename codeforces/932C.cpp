// codeforces 932C
#include <iostream>

using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;
    
    return d;
}

pair<int, int> solve(int n, int a, int b) {
    int x, y;
    // 베주 항등식
    int g = extended_gcd(a, b, x, y);
    
    if (n % g) return {-1, -1};

    // g = ax + by;
    // n = acx + bcy;

    long long c = n / g;
    int ag = a / g;
    int bg = b / g;
    long long x0 = c * x;
    long long y0 = c * y;

    long long maxk;
    if (y0 >= 0)
        maxk = y0 / ag;
    else
        maxk = -((-y0 + ag - 1) / ag);

    return {x0 + bg * maxk, y0 - ag * maxk};
}

void printLengthedLoop(int &idx, int len) {
    int start = idx++;
    while(--len) 
        cout << idx++ << " ";
    cout << start;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    auto [x, y] = solve(n, a, b);
    if (y < 0 || x < 0) {
        cout << -1;
    } else {
        int idx = 1;
        while(x--) {
            printLengthedLoop(idx, a);
            if (x > 0 || y > 0) cout << " ";
        }
        
        while(y--) {
            printLengthedLoop(idx, b);
            if (y > 0) cout << " ";
        }
    }
}