#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

int a[N];
map<int, int> cache;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, ans;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    partial_sum(a, a + n, a);
    cin >> m;
    while(m --){
        cin >> k;
        if(cache.count(k) == 0){
            ans = 0;
            for(int s = 1, t = k; s < n; s += t, t *= k){
                ans += a[n - 1] - a[s - 1];
            }
            cache[k] = ans;
        }
        else ans = cache[k];
        cout << ans << endl;
    }
    return 0;
}