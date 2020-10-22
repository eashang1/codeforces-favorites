#include <iostream>
#include <map>
#include <utility>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        map<pair<int,int>, int> ind;
        map<pair<int,int>, int> freq;
        int l = 0, r = 0, vert = 0, horz = 0, len = 10e9;
        freq[{0,0}] = 1;
        ind[{0,0}] = 0;
        for (int i = 0; i < n; i++) 
        {
            if(s[i] == 'R'){horz++;}
            else if(s[i] == 'U'){vert++;}
            else if(s[i] == 'L'){horz--;}
            else{vert--;}
            if(freq[{horz,vert}] != 0)
            {
                if(i - ind[{horz, vert}] < len)
                {
                    r = i+1;
                    l = ind[{horz, vert}]+1;
                    len = i - ind[{horz, vert}];
                }
            }
            ind[{horz, vert}] = i+1;
            freq[{horz, vert}]++;
        }
        if(l == 0 && r == 0){cout << -1 << "\n";}
        else{cout << l << " " << r << "\n";}
    }
    return 0;
}