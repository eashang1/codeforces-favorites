#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int>g[1000000];
vector<int> used(1000000, 0);
vector<int> used1(1000000, 0);
set<int> dist;
map<int,int> degree;
map<int,int> isLeaf;
bool odd = false;
int next = 0;
 
void addEdge(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}
 
void dfs(int v, int d)
{
    used[v] = 1;
    for (int vert : g[v])
    {
        if(used[vert] != 1)
        {
            if(isLeaf[vert] == 1)
            {
                //cout << vert << " " << d << "\n";
                dist.insert(d);
                if(1 == d%2 && d>1){odd = true;}
            }
            dfs(vert, d+1);
        }
    }
}
    
int main()
{
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        addEdge(a,b);
        degree[a]++;
        degree[b]++;
    }
    
    int start = 0;
    for (pair p : degree)
    {
        if(p.second == 1)
        {
            //cout << p.first << "\n";
            isLeaf[p.first] = 1;
            start = p.first;
        }
    }
    
    dfs(start,1);
    
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        if(isLeaf[i] != 1)
        {
            //cout << i << " ";
            for (auto vertex : g[i])
            {
                if(isLeaf[vertex]){temp++;}
            }
            //cout << temp << "\n";
        }
        cnt += max(0,(temp-1));
    }
    
    // for (auto i : dist) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    
    if(odd){cout << 3 << " " << n-1-cnt << "\n";}
    else{cout << 1 << " " << n-1-cnt << "\n";}
    return 0;
}