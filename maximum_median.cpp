#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    ll n,k; cin >> n >> k;
    ll nums[n];
    for (int i = 0; i < n; i++) {cin >> nums[i];}
    sort(nums, nums + n);
    ll med = n/2, end = 1, rtn = nums[med];
    for (int i = med; i < n - 1; i++)
    {
        if((nums[i+1]-nums[i])*(i-med+1) > k){break;}
        k -= (nums[i+1]-nums[i])*(i-med+1);
        end = i - med + 2;
        rtn = nums[i+1];
    }
    if(end != 0){rtn += k/end;}
    cout << rtn << "\n";
    return 0;
}