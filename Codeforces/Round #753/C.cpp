#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;
int a[N];

void solve() {
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int mmax = a[0];
    int cnt = a[0];
    for(int i=1;i<n;i++){
        a[i]-=cnt;
        mmax=max(mmax,a[i]);
        cnt+=a[i];
    }
    cout<<mmax;
}

signed main()
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