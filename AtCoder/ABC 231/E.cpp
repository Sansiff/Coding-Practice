#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i,l,r) for(int i = l; i <= r; i ++)

const int N = 1e5 + 10;
int n, m;
int a[100], f[100];

int fuc(int x, int i){
    if(i == 1) return x;
    int t = x % a[i];
    if(fuc(t, i - 1) + x / a[i] < fuc(x, i - 1))
        return fuc(x, i - 1);
    else return fuc(t, i - 1) + x / a[i];
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    cout << fuc(m, n);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}