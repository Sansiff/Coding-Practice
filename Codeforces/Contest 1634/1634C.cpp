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

void solve() {
    int n, k; cin >> n >> k;
    int cnt1 = (n * k + 1) / 2, cnt2 = n * k / 2;
    vector<int> ans[n + 1];
    for (int i = 1; i <= n; i++){
        if(cnt1>=k) {
            int res = k;
            while(res){
                ans[i].push_back(cnt1*2-1);
                cnt1--;
                res--;
            }
        }
        else if(cnt2 >= k) {
            int res = k;
            while(res){
                ans[i].push_back(cnt2*2);
                cnt2--, res--;
            }
        }
        else {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        for(auto x:ans[i])
            cout << x << " ";
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
    }
    return 0;
}