
//  242 一个简单的整数问题
//  Binary Indexed Tree

#include <bits/stdc++.h>
#define int long long 
#define lowbit(x) (x & -x)

using namespace std;

const int N = 1e5 + 10;

int bit[N], arr[N], n, m;

void update(int x, int k){
    for(; x <= n; x += lowbit(x)){
        bit[x] += k;
    }
}

int query(int x){
    int res = 0;
    for(; x; x -= lowbit(x)){
        res += bit[x];
    }
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i ++){
        update(i, arr[i] - arr[i - 1]);
    }

    while(m --){
        char c; cin >> c;
        if(c == 'C'){
            int l, r, d; cin >> l >> r >> d;
            update(l, d); update(r + 1, -d);
        }
        else{
            int x; cin >> x;
            cout << query(x) << endl;
        }
    }

    return 0;
}
