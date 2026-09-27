#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int par[1005];
int group_sz[1005];

int find (int node)
{
    if (par[node] == -1)
        return node;

    int leader = find (par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union (int node1, int node2)
{
    int leader1 = find (node1);
    int leader2 = find (node2);
    if (group_sz[leader1] >= group_sz[leader2])
    {
        par[leader2] = leader1;
        group_sz[leader1] += group_sz[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_sz[leader2] += group_sz[leader1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset (par, -1, sizeof(par));
    memset (group_sz, 0, sizeof(group_sz));

    dsu_union (1, 2);
    dsu_union (1, 4);
    dsu_union (2, 5);
    dsu_union (3, 0);

    for (int i = 0; i <= 6; i++)
        cout << i << " -> " << par[i] << endl;
    
    return 0;
}