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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    map<string, int> mp;
    vector<set<string>> arr(n + 5);
    vector<string> name(n + 5);
    int cnt = 1;
    while(n --){
        string s; cin >> s;
        if(!mp[s]) {
            name[cnt] = s;
            mp[s] = cnt ++;
        }
        int t; cin >> t;
        while(t --){
            string x; cin >> x;
            arr[mp[s]].insert(x);
        }
    }
    for(auto& st : arr){
        vector<string> tmp; set<string> del;
        for(auto x : st) tmp.push_back(x);
        for(auto a : tmp){
            for(auto b : tmp){
                if(a == b) continue;
                string sa = a, sb = b;
                reverse(all(sa)), reverse(all(sb));
                if(sa.length() < sb.length()) swap(sa, sb);
                if(sa.substr(0, sb.length()) == sb) {
                    reverse(all(sb));
                    del.insert(sb);
                }
            }
        }
        for(auto x : del){
            st.erase(x);
        }
    }
    cout << cnt - 1 << '\n';
    for(int i = 1; i < cnt; i ++){
        cout << name[i] << ' ' << arr[i].size();
        for(auto x : arr[i]){
            cout << ' ' << x;
        }
        cout << '\n';
    }
    
    return 0;
}