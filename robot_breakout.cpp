#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
       int n; cin >> n;
       int nums[n][6];
       for (int j = 0; j < n; j++)
       {
           cin >> nums[j][1] >> nums[j][2] >> nums[j][3] >> nums[j][4] >> nums[j][5] >> nums[j][6];
       }
       
       int minx = -100000, maxx = 100000, miny = -100000, maxy = 100000;
       
       for (int j = 0; j < n; j++) 
       {
           if(nums[j][3] == 0){minx = max(minx, nums[j][1]);}
           if(nums[j][4] == 0){maxy = min(maxy, nums[j][2]);}
           if(nums[j][5] == 0){maxx = min(maxx, nums[j][1]);}
           if(nums[j][6] == 0){miny = max(miny, nums[j][2]);}
       }
       
       if(miny > maxy || minx > maxx){cout << 0 << "\n";}
       else
       {
           cout << 1 << " " << minx << " " << miny << "\n";
       }
    }
    return 0;
}