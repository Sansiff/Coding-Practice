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

void solve(){
    int m; cin >> m;
    map<int, int> mp;
    VI a[m];
    for(int i = 0; i < m; i ++){
        int n; cin >> n;
        for(int j = 0; j < n; j ++){
            int x; cin >> x;
            a[i].push_back(x);
            if(mp[x]) mp[x] = 0;
            else mp[x] = 1;
        }
    }

    for(int i = 0; i < m; i ++){
        for(int& x : a[i]){
            if(mp[x]) {
                cout << "NO";
                return;
            }
        }
    }    
    cout << "YES\n";
    for(int i = 0; i < m; i ++){
        int t = 0;
        map<int, int> tt, ff;
        for(int& x : a[i]){
            if(tt[x]) tt[x] = 0, ff[x] = 1;
            else tt[x] = 1;
        }
        int cnt1 = a[i].size(), cnt2 = 0;
        vector<char> res(cnt1);
        for(int i = 0; i < n; i ++){
            if(ff[x]){
                if(!tt[x]) res[i] = 'L', tt[x] = 1;
                else res[i] = 'R', tt[x] = 0;
            }
            else {
                cnt2 ++;
            }
        }
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}