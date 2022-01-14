// 2060. 奶牛选美
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

const int N = 60;
int n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char g[N][N];
bool st[N][N];
vector<PII> b[2];

void dfs(vector<PII>& b, int x, int y){
    st[x][y] = 1; b.push_back({x, y});
    for(int i = 0; i < 4; i ++){
        int nx = x + dx[i], ny = y + dy[i];
        if(st[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] != 'X') 
            continue;
        dfs(b, nx, ny); 
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    }
    for(int i = 1, t = 0; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(g[i][j] == 'X' && !st[i][j])
                dfs(b[t ++], i, j);
        }
    }
    int res = 1e9;
    for(auto x : b[0]){
        for(auto y : b[1]){
            res = min(res, abs(x.first - y.first) + abs(x.second - y.second));
        }
    }
    cout << res - 1;
    return 0;
}