#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
     
void solve(){
    int n; cin >> n;
    vector<int> arr(n), brr(n);
    for(int &x : arr) cin >> x;
    for(int i = 0; i < n; i ++) brr[i] = arr[i];
    sort(brr.begin(), brr.end());
    int res = 0;
    while(arr != brr){
        res ++;
        if(res & 1){
            for(int i = 0; i < n; i += 2){
                if(arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
            }
        }
        else{
            for(int i = 1; i < n; i += 2){
                if(arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
            }
        }
    }    
    cout << res;
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