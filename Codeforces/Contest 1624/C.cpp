#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define rep(i, l, r) for(int i = l; i < r; i ++)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;

int f[50];

void read(VI& a){
    for(int& x : a) cin >> x;
}

void solve(){
    int n; cin >> n;
    VI a(n); read(a);
    vector<bool> vis(n + 1, false);
    rep(i, 0, n){
        while(a[i] > n) a[i] /= 2;
        while(vis[a[i]]){
            a[i] /= 2;
        }
        if(a[i] < 1){
            cout << "NO"; return;
        }
        vis[a[i]] = true;
    }
    cout << "YES";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = 1, f[1] = 2;
    rep(i, 2, 40) f[i] = f[i - 1] * 2; 
    int _; cin >> _;
    while(_--){
        solve();
        cout << endl;
    }
    return 0;
}