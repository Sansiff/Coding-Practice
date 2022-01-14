#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve() {
    int a, b; cin >> a >> b;
	if(a <= b / 3 || b <= a / 3){
		cout << min(a, b);
		return;
	}
	int l=0,r=((a+b)>>2)+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if((mid<=a&&mid<=3*b)||(mid<=b&&mid<=3*a)) l=mid;
		else r=mid;
	}
	cout << l;
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