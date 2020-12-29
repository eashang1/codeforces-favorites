#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        
        int cur = n;
        vector<int> rtn;
        for (int i = n-1; i > 2; i--)
        {
            if(cur/i + (0 != cur%i) > i)
            {
                rtn.push_back(n);
                rtn.push_back(i);
                cur = (cur/i + (0 != cur%i));
            }
            
            rtn.push_back(i);
            rtn.push_back(n);
        }
        
        while(cur != 1)
        {
            rtn.push_back(n);
            rtn.push_back(2);
            cur = (cur/2+ (0 != cur%2));
        }
        
        cout << rtn.size()/2 << "\n";
        for (int i = 0; i < rtn.size(); i+=2){cout << rtn[i] << " " << rtn[i+1] << "\n";}
    }
    return 0;
}