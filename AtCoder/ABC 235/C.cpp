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
typedef vector<PII> VPII;
void read(VI& a){
    for(int& x : a) cin >> x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    VI arr(n); map<int, int> mp;
    VII po(n + 10);
    int cnt = 0, idx = 1;
    for(int& x : arr){
        cin >> x;
        if(!mp[x]) mp[x] = ++ cnt;
        po[mp[x]].push_back(idx ++);
    }
    
    while(q --){
        int a, k; cin >> a >> k;
        if(!mp[a]) cout << -1;
        else{
            if(k > po[mp[a]].size()) cout << -1;
            else cout << po[mp[a]][k - 1];
        }
        cout << '\n';
    }
    return 0;
}