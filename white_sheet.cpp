
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    ll x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    ll area = (x2-x1)*(y2-y1);
    ll part1 = (min(y2, y4)-max(y1,y3)) * (min(x2, x4)-max(x1,x3)); 
    ll part2 = (min(y2, y6)-max(y1,y5)) * (min(x2, x6)-max(x1,x5));
    ll part3 = (min(min(y4, y6),y2)-max(max(y3,y5),y1)) * (min(min(x4, x6),x2)-max(max(x3,x5),x1));
    if(min(y2, y4)-max(y1,y3) < 0 || min(x2, x4)-max(x1,x3) < 0){part1 = 0;}
    if(min(y2, y6)-max(y1,y5) < 0 || min(x2, x6)-max(x1,x5) < 0){part2 = 0;}
    if(min(min(y4, y6),y2)-max(max(y3,y5),y1) < 0 || min(min(x4, x6),x2)-max(max(x3,x5),x1) < 0){part3 = 0;}
    if(area - part1 - part2 + part3 > 0){cout << "YES" << "\n";}
    else{cout << "NO" << "\n";}
    return 0;
}