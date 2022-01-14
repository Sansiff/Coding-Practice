#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;

char a[N],b[N];
int ans[N],cnt;
int n;

void solve() {
    cin >> n;
    cnt = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i])
            ans[++cnt]=i;
    }
    if(cnt==0) {
        cout<<0<<endl;
    }
    else{
        cout << '1' << endl;
        cout<<cnt << " ";
        for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t --){
        solve();
    }
    return 0;
}