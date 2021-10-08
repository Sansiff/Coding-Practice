
//  1562A The Miracle and the Sleeper
//  greedy *800

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
     
void solve(){
    int a, b; cin >> a >> b;
    if(a >= 2 * b) cout << (a - 1) / 2;
    else cout << a % b;
}

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t --){
        solve();
        if(t) cout << endl;
    }
    return 0;
}