
//  1561B Charmed by the Game 
//  math *1300

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
     
void solve(){
    int n, m; cin >> n >> m;
    int sum = n + m;
    if(n < m) swap(n, m);
    int r = (sum + 1) / 2 + m;
    int l = (sum / 2) - m;
    if(sum & 1){
        
        cout << (r - l + 1) << endl;
        for(int i = l; i <= r; i ++){
        cout << i << ' ';
        }
    }
    else{
        cout << (r - l) / 2 + 1 << endl;
        for(int i = l; i <= r; i += 2){
            cout << i << ' ';
        }    
    }
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