#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        ll a[n];
        map<ll,ll> used;
        bool done = false;
        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            while(a[i] != 0)
            {
                if(a[i]%k > 1){done = true; break;}
                if(a[i]%k == 1){used[cur]++;}
                if(used[cur] > 1){done = true; break;}
                a[i] /= k;
                cur++;
            }
            if(done){break;}
        }
        
        if(done){cout << "NO" << "\n";}
        else{cout << "YES" << "\n";}
    }
    return 0;
}