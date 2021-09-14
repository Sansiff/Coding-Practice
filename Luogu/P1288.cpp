
// 1288
// 2021.9.14

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        if(x) res ++;
    }
    if(res & 1) cout << "YES";
    else cout << "NO";
    return 0;
}