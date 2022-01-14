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

const int N  = 3e5 + 10;
int trie[N * 31][10], idx;
void insert(int x){
    int p = 0;
    for(int i = 30; ~i; i --){
        int u = x >> i & 1;
        if(!trie[p][u]) trie[p][u] = ++ idx;
        p = trie[p][u];
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 30; ~i; i --){
        int u = x >> i & 1;
        if(trie[p][!u]) res += 1 << i, p = trie[p][!u];
        else p = trie[p][u];
    }
    return res;
}

void solve(){
    int n, k; cin >> n >> k;
    VI a(n); read(a);

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << endl;
    }
    return 0;
}