#include <bits/stdc++.h>
#define int long long 

using namespace std;

signed main()
{
    int t; cin >> t;
    while(t --){
        int x, y; cin >> x >> y;
        if(x > y) cout << x + y << endl;
        else cout << y - y % x / 2 << endl;
    }

    return 0;
}