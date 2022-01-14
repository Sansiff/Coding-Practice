#include <bits/stdc++.h>
using namespace std;
const int N = 5e6;
map<string, int> mp;
int idx;
vector<int> res[N];
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int m; cin >> m;
        while(m --){
            string s; cin >> s;
            if(!mp[s]) mp[s] = ++ idx;
            res[mp[s]].push_back(i);
        }
    }

    int t; cin >> t;
    while(t --){
        string x; cin >> x;
        for(int x : res[mp[x]]) cout << x << ' ';
        if(t) cout << endl;
    }
    return 0;
}