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

const int N = 55, M = N * N;
int n, m, g[N][N], dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
bool st[N][N];

int bfs(int sx, int sy){
    int area = 0;
    queue<PII> q; q.push({sx, sy});
    st[sx][sy] = 1;
    while(q.size()){
        auto b = q.front(); q.pop();
        area++;
        rep(i, 0, 4){
            int nx = b.fi + dx[i], ny = b.se + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(st[nx][ny]) continue;
            if(g[b.fi][b.se] >> i & 1) continue;
            st[nx][ny] = 1; q.push({nx, ny});
        }
    }
    return area;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i, 0, n)
        rep(j, 0, m)
            cin >> g[i][j];
    int cnt = 0, area = 0;
    rep(i, 0, n)
        rep(j, 0, m)
            if(!st[i][j])
                area = max(area, bfs(i, j)), cnt ++;
    cout << cnt << endl;
    cout << area << endl;
    return 0;
}