// 2005. 马蹄铁
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

int n, ans = 0, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool st[7][7];char g[7][7];

void dfs(int x, int y, int l, int r){
    st[x][y] = 1;
    if(l == r){
        ans = max(l + r, ans); 
    }
    rep(i, 0, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(!st[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= n){
            if(g[nx][ny] == '(' && !r){
                dfs(nx, ny, l + 1, r);
            }
            if(g[nx][ny] == ')'){
                dfs(nx, ny, l, r + 1);
            }
        }
    }
    st[x][y] = 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            cin >> g[i][j];
        }
    }
    if(g[1][1] == ')') {
        cout << 0; return 0;
    }
    dfs(1, 1, 1, 0);
    cout << ans;
    return 0;
}