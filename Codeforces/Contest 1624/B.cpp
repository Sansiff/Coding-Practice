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

void solve(){
    int a, b, c; cin >> a >> b >> c;
    bool flag = false;
    if(c - b == b - a) flag = true;
    //todo a
    if((2 * b - c > 0) && (b - (c - b)) % a == 0) {
        flag = true;
    }
    //todo b
    if(((a + c) / 2 > 0) && ((c - a) % 2 == 0) && ((a + c) / 2) % b == 0) {
        flag = true;
    }
    //todo c
    if((2 * b - a > 0) && (b + (b - a)) % c == 0) {
        flag = true;
    }
    if(flag) cout << "YES";
    else cout << "NO";
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