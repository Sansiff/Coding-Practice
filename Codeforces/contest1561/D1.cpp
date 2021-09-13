
// 1561D1 Up the Strip (simplified version)
// data structures, dp  *1700

#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main()
{   
    int n, m; cin >> n >> m;
    vector<int> f(n + 2);
    int sum = 1; f[1] = 1;
    for(int i = 2; i <= n; i ++){
        f[i] = sum;
        for(int j = 2, r; j <= i; j = r + 1){
            r = i / (i / j);
            f[i] = (f[i] + (r - j + 1) * f[i / j]) % m;
        }
        sum = (sum + f[i]) % m;
    }
    cout << f[n];

    return 0;
}