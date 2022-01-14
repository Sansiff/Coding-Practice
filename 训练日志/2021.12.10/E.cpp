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

const int N = 1e6;
int s[N];
void init(){
    for(int i = 1; i <= 1e5; i ++) s[i] += s[i - 1] + i;
}

void solve(){
    int n; cin >> n;
    if(*lower_bound(s, s + 100100, n) - n == 1) cout << lower_bound(s, s + 100100, n) -s + 1;
    else cout << lower_bound(s, s + 100100, n) - s;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}