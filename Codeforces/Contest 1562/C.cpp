
//  1562C Rings
//  constructive algorithms *1500

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
     
void solve() {
	int n; cin >> n;
	string s; cin >> s; 
    s = " "+ s;
	for(int i = 1; i <= n / 2; i ++){
		if(s[i]=='0'){
			cout << i << " " << n << " " << i + 1 << " " << n << endl;
			return;
		}
	}
    for(int i = n / 2 + 1; i <= n; i ++){
		if(s[i]=='0'){
			cout<< 1 << " " << i << " " << 1 << " " << i - 1 << endl;
			return;
		}
	}
	cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << endl;
}

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t --){
        solve();
        if(t) cout << endl;
    }
    return 0;
}