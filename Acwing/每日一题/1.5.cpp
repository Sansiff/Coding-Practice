// 2019. 拖拉机
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

const int N = 1010;
bool g[N][N], st[N][N];
int dist[N][N], n, sx, sy;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int i, int j){
    memset(dist, 0x3f, sizeof dist);
    deque<PII> dq;
    dq.push_back({i, j});
    dist[i][j] = 0;
    while(dq.size()){
        auto b = dq.front(); dq.pop_front();
        if(st[b.fi][b.se]) continue;
        st[b.fi][b.se] = 1;
        for(int i = 0; i < 4; i ++){
            int x = b.fi + dx[i], y = b.se + dy[i];
            if(x >= 0 && x < N && y >= 0 && y < n){
                int w = 0;
                if(g[x][y]) w = 1;
                if(dist[x][y] > dist[b.fi][b.se] + w){
                    dist[x][y] = dist[b.fi][b.se] + w;
                    if(!w) dq.push_front({x, y});
                    else dq.push_back({x, y});
                } 
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> sx >> sy;
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        g[x][y] = 1;
    }
    bfs(sx, sy);
    cout << dist[0][0];
    return 0;
}