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
typedef vector<vector<int>> VII;
typedef vector<PII> VPII;
void read(VI& a){
    for(int& x : a) cin >> x;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == n - 1 && n == 4)
    {
        cout << "-1\n";
        return;
    }
    vector<bool> st(n, 0);
    if (k == n - 1)
    {
        cout << 1 << ' ' << 3 << '\n';
        cout << n - 2 << ' ' << n - 1 << '\n';
        st[1] = st[3] = st[n - 2] = st[n - 1] = 1;
        vector<int> res;
        for (int i = n - 2; i >= 0; i--)
        {
            if (st[i])
                continue;
            if (!st[n - 1 - i])
            {
                cout << n - 1 - i << ' ' << i << '\n';
                st[i] = st[n - 1 - i] = 1;
            }
            else
                res.push_back(i);
        }
        if (res.empty())
            return;
        cout << res[1] << ' ' << res[0] << '\n';
        return;
    }
    cout << k << ' ' << n - 1 << '\n';
    st[k] = 1, st[n - 1] = 1;
    if (!k)
    {
        for (int i = 1; i < n; i++)
        {
            if (st[i])
                continue;
            cout << i << ' ' << n - 1 - i << '\n';
            st[i] = 1;
            st[n - 1 - i] = 1;
        }
        return;
    }

    cout << 0 << ' ' << n - 1 - k << '\n';
    st[0] = 1;
    st[n - 1 - k] = 1;
    for(int i = 1; i < n; i ++ ) {
        if(st[i]) continue;
        cout << i << ' ' << n - 1 - i << '\n';
        st[i] = 1;
        st[n - 1 - i] = 1;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
    }
    return 0;
}