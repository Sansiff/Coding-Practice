#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

bool check(int a, int b, int n){
    if(!b) return (a == n);
    if(n <= a && a % b == n % b) return true;
    return check(b, a % b, n);
}

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a < b) swap(a, b);
    if(check(a, b, c)) cout << "YES";
    else cout << "NO";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}