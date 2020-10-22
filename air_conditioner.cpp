#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    int q; cin >> q;
    while(q--)
    {
        int n,m; cin >> n >> m;
        ll t[n];
        ll l = 0, h = 0;
        map<ll, pair<ll, ll>> rel;
        map<int,int> freq;
        for (int i = 0; i < n; i++) 
        {
            cin >> t[i];
            cin >> l >> h;
            if(freq[t[i]] > 0)
            {
                rel[t[i]].first = max(l, rel[t[i]].first);
                rel[t[i]].second = min(h, rel[t[i]].second);
            }
            else
            {
                rel[t[i]].first = l;
                rel[t[i]].second = h;
            }
            freq[t[i]]++;
        }
        sort(t,t+n);
 
        bool done = false;
        ll curmax = m+t[0], curmin = m-t[0];
        for (int i = 0; i < n; i++)
        {
            if(i > 0)
            {
                curmax += t[i]-t[i-1];
                curmin -= t[i]-t[i-1];
            }
            
            if(curmax >= rel[t[i]].first){curmax = min(curmax, rel[t[i]].second);}
            else{done = true; break;}
            
            if(curmin <= rel[t[i]].second){curmin = max(curmin, rel[t[i]].first);}
            else{done = true; break;}
        }
        
        if(done){cout << "NO" << "\n";}
        else{cout << "YES" << "\n";}
    }
    return 0;
}
