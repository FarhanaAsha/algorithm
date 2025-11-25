// Traffic problem in Onlinejudge

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        vector<int> busy(n + 1);
        for (int i = 1; i <= n; i++) cin >> busy[i];

        int r;
        cin >> r;
        vector<Edge> edges;
        for (int i = 0; i < r; i++)
        {
            int u, v;
            cin >> u >> v;
            int w = (busy[v] - busy[u]);
            w = w * w * w;
            edges.push_back({u, v, w});
        }

        int INF = INT_MAX;
        vector<int> dist(n + 1, INF);
        dist[1] = 0;


        for (int i = 1; i <= n - 1; i++)
        {
            for (auto &e : edges)
            {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
                {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int v;
            cin >> v;
            if (dist[v] == INF || dist[v] < 3)
            {
                cout << "?\n";
            }
            else
            {
                cout << dist[v] << "\n";
            }
        }
    }
    return 0;
}

