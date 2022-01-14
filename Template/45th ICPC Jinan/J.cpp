#include <bits/stdc++.h>
#define LL long long 
#define int long long 
using namespace std;

const int N = 110;

int h[N], e[N * 2], ne[N * 2], dep[N], w[N], idx;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int fa, int depth){
    dep[u] = depth;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        else dfs(j, u, depth + 1);
    }
}

int32_t main()
{
    memset(h, -1, sizeof h);
    int n; cin >> n;
    
	for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, -1, 1);
	vector<int> a, b;
    for(int i = 1; i <= n; i ++){
		if(dep[i] & 1) a.push_back(i);
		else b.push_back(i);
	}
	if(a.size() > b.size()) swap(a, b);
	for(int i = 0; i < b.size(); i ++) w[b[i]] += ((LL)1 << 59);
	for(int i = 0; i < a.size(); i ++){
		w[a[i]] = (((LL)1 << 60) - 1) >> 1;
		w[a[i]] -= ((LL)1 << i);
		for(int j = h[a[i]]; ~j; j = ne[j]){
			int t = e[j];
			w[t] += ((LL)1 << i);
		}
	}
	for(int i = 1; i <= n; i ++) cout << w[i] << ' ';
	//cout << endl <<  (w[1] | w[2]) << ' ' << (w[1] | w[3]);
	
    return 0;
}