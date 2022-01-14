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
	int n,k; cin >> n >> k;
	vector<int>vis(n+1), dis(n+1),dis2(n+1), du(n+1);
	vector<vector<int> > a(n+1);
	queue<int>q;
	for(int i = 0; i < k; i ++){
		int x; cin >> x;
        q.push(x);
		vis[x]=1;
	}
	for(int i = 1; i < n; i ++){
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		du[u] ++;
		du[v] ++;
	}
	while(q.size()){
		int u=q.front();q.pop();
		for(int v:a[u]){
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	vis=vector<int>(n+1);
	vis[1]=1;q.push(1);
	while(q.size()){
		int u=q.front();q.pop();
		for(int v:a[u]){
			if(vis[v]) continue;
			dis2[v]=dis2[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	int tag=0;
	for(int i=2;i<=n;++i) if(du[i]==1&&dis[i]>dis2[i]) tag=1;
	if(tag) cout << "YES";
	else cout << "NO";
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