#include <iostream>
#include <map>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        int x[m], y[m];
        map<int,int> val;
        for (int i = 0; i < m; i++) 
        {
            cin >> x[i] >> y[i];
            val[x[i]] = y[i];
        }
        
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if(x[i] != y[i])
            {
                cnt++;
            }
        }
        
        map<int,int> cycle;
        for (int i = 0; i < m; i++)
        {
            if(x[i] == y[i] || cycle[x[i]]){continue;}
            
            bool clear = false;
            
            map<int,int> done;
            int cur = x[i];
            while(val[val[cur]] != 0)
            {
                done[cur]++;
                cur = val[cur];
                if(done[cur]){cnt++; clear = true; break;}
            }
            
            if(clear)
            {
                map<int,int> done1;
                cur = x[i];
                while(val[val[cur]] != 0)
                {
                    done1[cur]++;
                    cycle[cur]++;
                    cur = val[cur];
                    if(done1[cur]){break;}
                }
            }
        }
        
        cout << cnt << "\n";
    }
    return 0;
}