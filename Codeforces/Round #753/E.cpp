#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

void solve() {
	int n,m; cin >> n >> m;
	string s; cin >> s;
	int tx=0,ty=0;
	int lx=0,rx=0,ly=0,ry=0;
	for(int i=0;i<(int)s.size();++i){
		if(s[i]=='L') ty-=1;
		if(s[i]=='R') ty+=1;
		if(s[i]=='U') tx-=1;
		if(s[i]=='D') tx+=1;
		int rex=lx,rey=ly;
		lx=min(lx,tx);
		rx=max(rx,tx);
		ly=min(ly,ty);
		ry=max(ry,ty);
		if(abs(lx)+rx>=n||abs(ly)+ry>=m) {
			cout << 1+abs(rex) << ' ' << 1+abs(rey);
			return;
		}
	}
	cout << 1+abs(lx) << ' ' << 1 + abs(ly);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t --){
        solve();
        cout << "\n";
    }

    return 0;
}