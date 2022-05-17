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


void solve() {
	int l, r, k; cin >> l >> r >> k;
	if(l == r){
		if(r < 2) cout << "NO";
		else cout << "YES";	
		return;
	}
	int c1 = (r - l + 1) >> 1, c2 = c1;
	if(l & 1 && r & 1) c1 ++;
	if(k >= c1) cout << "YES";
	else cout << "NO";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << '\n';
    }
    return 0;
}
