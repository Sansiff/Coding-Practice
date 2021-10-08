
// 1562B Scenes From a Memory
// constructive algorithms *1000

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

bool st[150];

void solve(){
	int n; string s; 
    cin >> n >> s;
	for(int i = 0; i < n; i ++){
		if(st[s[i] - '0']){
			cout << 1 << endl;
			cout << s[i];
			return;
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			int t = (s[i] - '0') * 10 + s[j] - '0';
			if(st[t]) {
				cout << 2 << endl;
				cout << s[i] << s[j];
				return;
			}
		}
	}
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 2; i <= 100; i ++){
		for(int j = 2; j <= i / j; j ++){
			if(i % j == 0) st[i] = 1;
 		}
	}
	st[1] = 1;

	int t; cin >> t;
	while(t --){
		solve();
		if(t) cout << endl;
	}
	return 0;
}