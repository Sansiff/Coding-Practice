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
typedef vector<PII> VII;

const int N = 1e6;
char s[N];
void solve(){
    VI cnt(26);
    int n, k; cin >> n >> k;
    int res = 1;
    rep(i, 1, n + 1){
        cin >> s[i];
        cnt[s[i] - 'a'] ++;
    }
    int ct = 0;
    for(int i = 0; i < 26; i ++){
        if(cnt[i] & 1) ct ++;
    }
    int m = n - ct;
    m /= 2;
    int a = m / k, b = m % k;
    res = a * 2 + (ct + b * 2 >= k);
    cout << res;
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