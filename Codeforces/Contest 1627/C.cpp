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

const int N = 2e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void solve(){
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    int n; cin >> n;
    VI cnt(n + 1); VPII edg(n + 1);
    rep(i, 1, n){
        int a, b; cin >> a >> b;
        edg[i] = {a, b};
        add(a, b); add(b, a); cnt[a] ++, cnt[b] ++;
    }
    if(*max_element(all(cnt)) > 2){
        cout << -1; return;
    }
    else{
        map<PII, int> mp;
        queue<int> q;
        int t = 0;
        for(int i = h[1]; ~i; i = ne[i]){
            if(!t) mp[{1, e[i]}] = 2, mp[{e[i], 1}] = 2, t = 1; 
            else mp[{1, e[i]}] = 3, mp[{e[i], 1}] = 3;
            q.push(e[i]), st[i] = 1;
        }
        st[1] = 1;
        while(q.size()){
            int t = q.front(); q.pop();
            int bef, nex = -1;
            for(int i = h[t]; ~i; i = ne[i]){
                if(!mp[{t, e[i]}]) nex = e[i];
                else bef = mp[{t, e[i]}];
            }
            if(nex == -1) continue;    
            if(bef == 2) mp[{t, nex}] = 3, mp[{nex, t}] = 3;
            else mp[{t, nex}] = 2, mp[{nex, t}] = 2;
            q.push(nex);
        }
        rep(i, 1, n){
            cout << mp[edg[i]] << ' ';
        }
    }
    
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