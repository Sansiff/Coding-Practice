#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin>>a[i];
    deque<int> q;
    if(a[n]!=n&&a[1]!=n) {
        cout << -1;
        return ;
    }
    q.push_back(n);
    int i,j;
    if(a[n]==n) i=1,j=n-1;
    else i=2,j=n;
    while(i<j){
        if(a[i]<a[j]) q.push_front(a[i]),i++;
        else q.push_back(a[j]),j--;
    }
    q.push_front(a[i]);
    for(int i=1;i<=n;i++) {
        cout<<q.front()<<" ";
        q.pop_front();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _; cin >> _;
    while(_ --){
        solve();
        cout << endl;
    }
    return 0;
}