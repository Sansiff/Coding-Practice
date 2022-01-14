// 2041. 干草堆
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

const int N = 1e6 + 10;
int t[N], res[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    while(k --){
        int a, b; cin >> a >> b;
        t[a] ++, t[b + 1] --;
    }
    for(int i = 1; i <= n; i ++)
        res[i] = res[i - 1] + t[i];
    sort(res + 1, res + n + 1);
    cout << res[n / 2 + 1];

    return 0;
}