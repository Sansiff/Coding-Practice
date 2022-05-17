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

const int p = 1e9 + 7;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));   
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= i; j ++){
            if(j == 0){
                dp[i][j] = 0; continue;
            }
            if(i == j){
                dp[i][j] = i; continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) / 2;
        }
    }
    cout << dp[n][m] * k;
}

int qpow(int a, int b, int p){
	int res = 1;
	while(b){
		if(b & 1) (res *= a) %= p, b --;
		else a = a * a % p, b >>= 1;	
	}
	return res;
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
