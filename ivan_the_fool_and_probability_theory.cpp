#include <iostream>
#define ll long long
using namespace std;
 
int fibonacci(int a)
{
    ll cura = 1;
    ll curb = 1;
    for (int i = 1; i < a; i++)
    {
        ll temp = curb;
        curb += cura;
        curb %= 1000000007;
        cura = temp;
    }
    return curb;
}
 
int main()
{
    ll n,m; cin >> n >> m;
    ll rtn1 = 0, rtn2 = 0;
    ll mod = 1000000007;
    rtn1 = (fibonacci(n)*2)%mod;
    rtn2 = (fibonacci(m)*2)%mod;
    rtn2 -= 2;
    cout << (rtn1 + rtn2)%mod << "\n";
    return 0;
}