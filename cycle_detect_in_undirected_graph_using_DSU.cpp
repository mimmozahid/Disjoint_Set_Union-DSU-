#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int par[1002];
int grp_sz[1002];

int dsu_find (int node)
{
    if (par[node] == -1) return node;

    int leader = dsu_find (par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union (int u, int v)
{
    int leader1 = dsu_find (u);
    int leader2 = dsu_find (v);

    if (grp_sz[leader1] >= grp_sz[leader2])
    {
        par[leader2] = leader1;
        grp_sz[leader1] += grp_sz[leader2];
    }
    else
    {
        par[leader1] = leader2;
        grp_sz[leader2] += grp_sz[leader1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset (par, -1, sizeof (par));
    memset (grp_sz, -1, sizeof (grp_sz));
    
    int n, e;
    cin >> n >> e;

    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int p = dsu_find (a), q = dsu_find (b);

        if (q == p)
            cycle = true;
        else
            dsu_union (a, b);
    }

    if (cycle)
        cout << "Cycle Detected" << endl;
    else   
        cout << "No Cycle Detected" << endl;
    
    return 0;
}