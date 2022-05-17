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

int a, n;
string f[1000010];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> n;
    string s2 = to_string(n);
    queue<int> q; q.push(1);
    map<int, int> mp;
    mp[1] = 0;
    while(q.size()){
        int t = q.front(); q.pop();
        string s1 = to_string(t);
        if(s1.length() > s2.length()) continue;
        if(t == n){
            cout << mp[t]; return 0;
        }
        int tf = t * a; string stf = to_string(tf);
        if(!mp[tf]) q.push(tf), mp[tf] = mp[t] + 1;
        if(s1[s1.length() - 1] != '0' && s1.length() >= 2){
            string ts = s1[s1.size() - 1] +  s1.substr(0, s1.length() - 1);
            if(!mp[stoi(ts)]){
                q.push(stoi(ts)); mp[stoi(ts)] = mp[t] + 1;
            }
        }
    }
    cout << -1;
    return 0;
}