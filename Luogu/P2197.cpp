
// P2197
// 2021.9.14

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
     
void solve(){
    int n; cin >> n;
    int res = 0;
    for(int i = 0; i < n;i ++){
        int x; cin >> x;
        res ^= x;
    }
    if(res) cout << "Yes";
    else cout << "No";
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