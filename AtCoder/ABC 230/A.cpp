#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i,l,r) for(int i = l; i <= r; i ++)

const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << "AGC";
    if(n < 10) cout << "00" << n;
    else if(n <= 41) cout << "0" << n;
    else cout << "0" << n + 1;
    
    return 0;
}