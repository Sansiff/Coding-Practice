#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i,l,r) for(int i = l; i <= r; i ++)

const int N = 1e5 + 10;
int a[N], b[N], n, m, in[N], p[N];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    cin >> n >> m;
    bool flag = true;
    rep(i, 1, n) p[i] = i;
    rep(i, 1, m) {
        cin >> a[i] >> b[i];
        in[a[i]] ++;
        in[b[i]] ++;
        int pa = find(a[i]), pb = find(b[i]);
        
        if(pa == pb) flag = false;
        if(in[a[i]] > 2 || in[b[i]] > 2) {
            flag = false;
        }
        p[pa] = pb; 
    }
    cout << (flag ? "Yes" : "No");
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}