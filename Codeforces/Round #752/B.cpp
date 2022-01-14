#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int& x : arr) cin >> x;
    if(n & 1){
        for(int i = 0; i < n - 1; i ++){
            if(arr[i] >= arr[i + 1]){
                cout << "YES";
                return;
            }
        }
        cout << "NO";
    }
    else cout << "YES";

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T --){
        solve();
        cout << endl;
    }

    return 0;
}