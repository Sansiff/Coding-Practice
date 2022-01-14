#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int fa[N], dist[N], b[N], p[N], n;
void add(int a, int b){
    fa[b] = a;
}
void solve(){
    vector<int> res;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> b[i];
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= n; i ++){
        fa[i] = b[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        dist[p[i]] = cnt ++;
    }
    for(int i = 1; i <= n; i ++){
        if(!fa[i]) res.push_back(0);
        else {
            int t = dist[i] - dist[fa[i]];
            if(t < 0) {
                cout << -1;
                return;
            }
            res.push_back(t);
        }
    }
    for(int x : res) cout << x << ' ';
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