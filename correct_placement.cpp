#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
using namespace std;
 
//O(n)
 
bool compare(pair<ll,ll> a, pair<ll,ll> b)
{
    return (a.first*a.second) < (b.first*b.second);
}
 
int main()
{
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<pair<ll,ll>> points;
        vector<pair<ll,ll>> original;
        map<pair<ll,ll>, int> ind;
        
        for (int i = 0; i < n; i++) 
        {
            pair<ll,ll> p;
            cin >> p.first >> p.second;
            points.push_back(p);
            original.push_back(p);
            ind[p] = i;
        }
        
        sort(points.begin(), points.end(), compare);
        
        for (int i = 0; i < n; i++) 
        {
            bool done = false;
            for (int j = 0; j < min(40ll,n); j++)
            {
                if((original[i].first > points[j].first && original[i].second > points[j].second) ||
                    (original[i].first > points[j].second && original[i].second > points[j].first))
                {
                    cout << ind[points[j]]+1 << " ";
                    done = true;
                    break;
                }
            }
            
            if(done){continue;}
            cout << -1 << " ";
        }
        cout << "\n";
    }
    return 0;
}