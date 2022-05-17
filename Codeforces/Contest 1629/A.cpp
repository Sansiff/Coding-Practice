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
typedef vector<char> VC;

void read(VI & a){for(int& x : a) cin >> x;}
void read(VC & a){for(char& x : a) cin >> x;}

void solve(){
	int n, k; cin >> n >> k;
	VPII arr(n);
	rep(i, 0, n) cin >> arr[i].fi;
	rep(i, 0, n) cin >> arr[i].se;
	sort(all(arr));
	rep(i, 0, n){
		if(k >= arr[i].fi) k += arr[i].se;
		else break;
	}	
	cout << k;
}	

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}