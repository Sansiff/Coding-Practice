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

void solve(){
    int n; cin >> n;
    vector<int> s(10);
    for(int i = 1; i <= n; i ++){
        int x; cin >> x; s[x] ++;
    }
    int res = s[4];
    res += s[3]; s[1] -= s[3];
    res += s[2] / 2;
    s[2] &= 1;
    if(s[2]) res ++, s[1] -= 2;
    if(s[1] > 0) res += (s[1] + 3) / 4;
    cout << res; 
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}