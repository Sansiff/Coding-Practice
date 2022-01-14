#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 10;

void solve(){
    vector<int> a(3);
    for(int& x : a) cin >> x;
    sort(a.begin(), a.end());
    if(a[0] + a[2] == 2 * a[1]){
        cout << 0;
    }
    else{
        int t = abs(a[0] + a[2] - 2 * a[1]);
        if(t % 3 == 0) cout << 0;
        else cout << 1;
    }
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t --){
        solve();
        cout << '\n';
    }

    return 0;
}