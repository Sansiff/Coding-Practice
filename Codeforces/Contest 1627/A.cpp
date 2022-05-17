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

const int N = 100;
char g[N][N];

void solve(){
    int n, m, r, c; cin >> n >> m >> r >> c;
    bool flag = 0;
    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            cin >> g[i][j];
            if(g[i][j] == 'B') flag = 1;
        }
    }
    if(flag){
        if(g[r][c] == 'B') {
            cout << 0; return;
        }
        else{
            rep(i, 1, n + 1){
                if(g[i][c] == 'B'){
                    cout << 1; return;
                }
            }
            rep(i, 1, m + 1){
                if(g[r][i] == 'B'){
                    cout << 1; return;
                }
            }
            cout << 2;
            return;
        }
    }
    else cout << -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << '\n';
    }
    return 0;
}
