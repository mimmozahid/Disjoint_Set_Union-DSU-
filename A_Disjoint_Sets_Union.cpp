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
    vector<int> par, rank, siz;
    int component;
    DSU (int n) : par(n+1, -1), rank (n+1, 0), siz (n+1, 1), component(n)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int find (int i)
    {
        return par[i] == i ? i : (par[i] = find (par[i]));
    }

    bool isSame (int u, int v)
    {
        return (find (u) == find (v));
    }

    int getSize (int node)
    {
        return siz[find(node)];
    }

    int cntComponent ()
    {
        return component;
    }

    void _union (int u, int v)
    {
        if ((u = find(u)) == (v = find(v)))
        {
            return;
        }
        else
        {
            component--;
        }

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
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    DSU d(n);

    for (int i = 0; i < m; i++)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;

        if (s == "union")
        {
            d._union(u, v);
        }
        else
        {
            cout << (d.isSame (u, v) ? "YES" : "NO") << endl;
        }
    }
    
    
    return 0;
}