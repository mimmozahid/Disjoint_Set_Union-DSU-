#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int par[1005];

int find (int node) //* Optimized recursive funtion...
{
    if (par[node] == -1)
        return node;

    int leader = find (par[node]);
    par[node] = leader;
    return leader;
}

// int find (int node) //! Using loop...
// {
//     while (node != -1)
//     {
//         node = par[node];
//     }

//     return node;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset (par, -1, sizeof(par));

    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    cout << find (4) << endl;
    
    return 0;
}