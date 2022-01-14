#include <bits/stdc++.h>

#define int long long 

using namespace std;

signed main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) arr[i] = i + 1;
    do{
        for(int x : arr) cout << x << ' ';
        cout << endl;
    }while(next_permutation(arr.begin(), arr.end()));

    return 0;
}