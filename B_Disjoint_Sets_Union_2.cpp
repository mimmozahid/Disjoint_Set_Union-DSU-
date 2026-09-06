#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

struct DSU
{
    vector<int> par, rank, siz, mini, maxi;
    int component;

    DSU (int n) : par(n+1), rank(n+1, 0), siz(n+1, 1), component(n), mini(n+1, -1), maxi(n+1, -1)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            mini[i] = maxi[i] = i;
        }
    }

    int find (int i)
    {
        return (par[i] == i? i : (par[i] = find (par[i])));
    }

    int getSize (int u)
    {
        return siz[find(u)];
    }

    bool isSame (int u, int v)
    {
        return find (u) == find (v);
    }

    int cntComponent ()
    {
        return component;
    }

    void _union (int u, int v)
    {
        if ((v = find (v)) == (u = find (u)))
            return;
        else
            component--;

        if (rank[u] > rank[v])
        {
            swap (u, v);
        }
        else if (rank[u] == rank[v])
        {
            rank[v]++;
        }

        par[u] = par[v];
        siz[v] += siz[u];
        mini[v] = min (mini[v], mini[u]);
        maxi[v] = max (maxi[v], maxi[u]);
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    DSU d(n);
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int u, v;
            cin >> u >> v;
            d._union (u, v);
        }
        else
        {
            int v;
            cin >> v;
            v = d.find (v);
            cout << d.mini[v] << " " << d.maxi[v] << " " << d.getSize(v) << endl;
        }
    }
    
    
    return 0;
}