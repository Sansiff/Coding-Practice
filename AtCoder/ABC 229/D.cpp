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

string s; int k, n; 

const int N = 3e5 + 10;
int sum[N];

bool check(int d){
    for(int i = 1; i + d - 1 <= n; i ++){
        if(sum[i + d - 1] - sum[i - 1] >= d - k) return true;
    }
    return false;
}

void solve(){
    cin >> s; cin >> k;
    int l = 1, r = s.length();
    n = r;
    s = ' ' + s;
    for(int i = 1; i <= r; i ++){
        if(s[i] == 'X') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];
    }
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    if(check(l)) cout << l;
    else cout << l - 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    solve();
    return 0;
}