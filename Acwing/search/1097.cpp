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

const int N = 1010;
int n, m, res;
char g[N][N];bool st[N][N];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
void bfs(int x, int y){
    st[x][y] = 1; res ++;
    queue<PII> q; q.push({x, y});
    while(q.size()){
        auto b = q.front(); q.pop();
        rep(i, 0, 8){
            int nx = b.fi + dx[i], ny = b.se + dy[i];
            if(st[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] != 'W')
                continue;
            st[nx][ny] = 1, q.push({nx, ny});
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i, 1, n + 1)
        rep(j, 1, m + 1)
            cin >> g[i][j];
    rep(i, 1, n + 1)
        rep(j, 1, m + 1)
            if(!st[i][j] && g[i][j] == 'W') 
                bfs(i, j);
    cout << res;
    return 0;
}