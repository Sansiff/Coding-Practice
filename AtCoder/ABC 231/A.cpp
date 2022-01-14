#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i,l,r) for(int i = l; i <= r; i ++)

const int N = 1e5 + 10;

void solve(){
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    sort(all(a));
    while(m --){
        int x; cin >> x;
        cout << n - (lower_bound(all(a), x) - a.begin()) << '\n'; 
    }
    return 0;
}