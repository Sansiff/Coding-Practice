#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i = l; i < r; i ++)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve(){
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> arr;
    rep(i, 0, n){
        int x; cin >> x;
        if(x >= l && x <= r) arr.push_back(x);
    }
    sort(all(arr));
    int sum = 0, cnt = 0;
    for(int x : arr){
        sum += x;
        if(sum > k) break;
        cnt ++;
    }
    cout << cnt;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}