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

int n, last, num, ans;

int chk(int x){
    int res = n - x + last;
    if(res >= n){
        res -= n;
        num --;
    }
    cout << "+ " << res << endl;
    ans += res;
    int R; cin >> R;
    last = x;
    return R;
}

void solve(){
    cin >> n;
    int l = 1, r = n - 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(chk(mid) <= num) r = mid - 1;
        else l = mid;
        num ++;
    }
    cout << "! " << l + ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}