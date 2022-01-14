#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    if(n & 1){
        if(n <= 3) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    else{
        cout << "YES" << endl;
    }

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T --){
        solve();
    }

    return 0;
}