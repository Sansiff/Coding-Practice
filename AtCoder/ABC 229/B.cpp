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
int qpow(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res *= a, b --;
        else a *= a, b /= 2;
    }
    return res;
}
char s[5][5];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void solve() {
    cin >> s[1] + 1; cin >> s[2] + 1;
    int cnt = 0;
    for(int i = 1; i <= 2; i ++ )
        for(int j = 1; j <= 2; j ++ ) 
            cnt += (s[i][j] == '#');
    if(cnt == 1) cout << "Yes";
    else {
        for(int i = 1; i <= 2; i ++ )
            for(int j = 1; j <= 2; j ++ ) 
                if(s[i][j] == '#') {
                    bool f = false;
                    for(int k = 0; k < 4; k ++ ) {
                        int a = i + dx[k], b = j + dy[k];
                        if(a < 1 || a > 2 || b < 1 || b > 2) continue;
                        if(s[a][b] == '#') f = true;
                    }
                    if(!f) {
                        cout << "No"; return;
                    }
                }
    cout << "Yes";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}