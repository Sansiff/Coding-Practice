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
int qpow(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res *= a, b --;
        else a *= a, b /= 2;
    }
    return res;
}
const int N = 2e5 + 10;
int p[N],res[N];
bool st[N];
vector<int> v[N];
int n,m;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for(int i=n;i>=1;i--){
        res[i]=cnt;
        cnt++;   
        st[i]=1;
        for(auto x:v[i]) {
            if(st[x]){
                int pa = find(i),pb = find(x);
                if(pa!=pb) p[pa]=pb,cnt--;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}