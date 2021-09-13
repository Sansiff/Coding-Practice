
// 1561D1 Up the Strip (simplified version)
// data structures, dp  *1900

#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main()
{   
    int n, m; cin >> n >> m;
    vector<int> f(n + 2), d(n + 2);
    f[1] = 1; int sum = 0;
    for (int i = 1; i <= n; i ++){
        d[i] = (d[i] + d[i - 1]) % m;
        f[i] = (f[i] + sum) % m;
        f[i] = (f[i] + d[i]) % m;
        sum = (sum + f[i]) % m;
        for (int j = 2; i * j <= n; j ++){
            d[i * j] = (d[i * j] + f[i]) % m;
            d[min((i + 1) * j, n + 1)] = (d[min((i + 1) * j, n + 1)] - f[i] + m) % m;
        }
    }
    cout << f[n];

    return 0;
}