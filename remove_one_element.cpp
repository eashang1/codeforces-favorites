#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {cin >> a[i];}
    vector<int> lens;
    int rtn = 0;
    int cur = a[0];
    int len = 1;
    lens.push_back(len);
    vector<int> process;
    for (int i = 1; i < n; i++)
    {
        if(a[i] > cur)
        {
            len++;
            cur = a[i];
            lens.push_back(len);
        }
        else
        {
            if(i-2>=0){process.push_back(i-2);}
            if(i-1>=0){process.push_back(i-1);}
            cur = a[i];
            len = 1;
            lens.push_back(len);
        }
        rtn = max(rtn, len);
    }
 
    for (auto i : process)
    {
        int j = i;
        if(j+2 > n-1){break;}
        int temp = lens[i];
        if(a[j] < a[j+2])
        {
            j += 2;
            temp++;
            while(a[j]<a[j+1] && j < n-1)
            {
                j++;
                temp++;
            }
        }
        rtn = max(rtn, temp);
    }
    cout << rtn << "\n";
    return 0;
}