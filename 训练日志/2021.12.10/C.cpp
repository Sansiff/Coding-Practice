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
const int N= 1000020;
int primes[N], cnt;
bool st[N];
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

void solve(){
    int n; cin >> n;
    int p1 = *lower_bound(primes, primes + 100010, 1 + n);
    int p2 = *lower_bound(primes, primes + 100010, p1 + n);
    cout << p1 * p2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_primes(1e6);
    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}