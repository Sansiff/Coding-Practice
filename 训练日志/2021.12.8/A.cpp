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
    set<int> s;
    int t1; cin >> t1;
    while(t1 --){
        int x; cin >> x; s.insert(x);
    }
    int t2; cin >> t2;
    while(t2 --){
        int x; cin >> x; s.insert(x);
    }
    if(s.size() < n) cout << "Oh, my keyboard!";
    else cout << "I become the guy.";

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}