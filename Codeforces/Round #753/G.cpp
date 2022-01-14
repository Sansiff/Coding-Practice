#include <bits/stdc++.h>
#define int long long 
using namespace std;

struct node{
    int i, a, b, c;
    int da, db;
};

bool cmp(node A, node B){
    return A.c < B.c;
}

bool cmpi(node A, node B){
    return A.i < B.i;
}


void solve(){
    int n, m; cin >> n >> m;
    vector<node> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i].a >> arr[i].b;
        arr[i].c = arr[i].a - arr[i].b;
        arr[i].i = i;
        sum += arr[i].c;
    }
    sort(arr.begin(), arr.end(), cmp);
    int t = 0;
    for(int i = 0; i < n; i ++){
        if(arr[i].a + arr[i].b - abs(arr[i].c) < m){
            if(arr[i].c > m) {
                t += m;
                arr[i].da = m;
            }
            if(arr[i].c < -m) {
                t -= m;
                arr[i].db = m;
            } 
        }
    }
    if(t >= 0){
        for(int i = 0; i < n; i ++){
            if(arr[i].a + arr[i].b - abs(arr[i].c) >= m){
                if(arr[i].a <= t){
                    arr[i].da = arr[i].a;
                    t -= arr[i].a;
                }
                else{
                    arr[i].da = t;
                    t -= t;
                }
            }
        }
        if(t > 0){
            for(int i = 0; i < n; i ++){
                if(arr[i].c < 0){
                    if(t & 1 && arr[i].a >= t / 2){
                        arr[i].da += t / 2;
                        arr[i].db -= t / 2;
                        t = 1;
                    }
                    else if(arr[i].a >= t / 2){
                        arr[i].da += t / 2;
                        arr[i].db -= t / 2;
                        t = 0;
                    }
                    else{
                        arr[i].da += arr[i].a;
                        arr[i].db -= arr[i].a;
                        t -= 2 * arr[i].a;
                    }
                }
            }
        }
    }
    if(t < 0){
        t = -t;
        for(int i = 0; i < n; i ++){
            if(arr[i].a + arr[i].b - abs(arr[i].c) >= m){
                if(arr[i].b <= t){
                    arr[i].db = arr[i].b;
                    t -= arr[i].b;
                }
                else{
                    arr[i].db = t;
                    t -= t;
                }
            }
        }
        if(t > 0){
            for(int i = 0; i < n; i ++){
                if(arr[i].c < 0){
                    if(t & 1 && arr[i].b >= t / 2){
                        arr[i].db += t / 2;
                        arr[i].da -= t / 2;
                        t = 1;
                    }
                    else if(arr[i].b >= t / 2){
                        arr[i].db += t / 2;
                        arr[i].da -= t / 2;
                        t = 0;
                    }
                    else{
                        arr[i].db += arr[i].b;
                        arr[i].da -= arr[i].b;
                        t -= 2 * arr[i].b;
                    }
                }
            }
        }
    }
        
    cout << t << endl;
    sort(arr.begin(), arr.end(), cmpi);
    for(int i = 0; i < n; i ++){
        cout << arr[i].da << ' ' << arr[i].db << endl;
    }
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t --){
        solve();
        cout << endl;
    }
    return 0;
}