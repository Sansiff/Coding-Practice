
// 1561C Deep Down Below
// gready

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct node{
    int l, k;
}arr[100010];

bool cmp(node a, node b){
    if(a.l == b.l) return a.k < b.k;
    return a.l < b.l;
}

void solve(){
    int n;  cin >> n;
    for(int i = 1; i <= n; i ++){
        int k, mx = 0, x; cin >> k;
        for(int j = 0; j < k; j ++){
            cin >> x; mx = max(mx, x - j + 1);
        }
        arr[i].l = mx, arr[i].k = k;
    }
    sort(arr + 1, arr + n + 1, cmp);
    int res = 0, temp = 0;
    for(int i = 1; i <= n; i ++){
        if(res + temp < arr[i].l) res = arr[i].l - temp;
        temp += arr[i].k;
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