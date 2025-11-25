//Not the best Problem in Lightoj

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int N, R;
        cin >> N >> R;
        vector<vector<pair<int,int>>> adj(N + 1);

        for (int i = 0; i < R; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        long long INF = LLONG_MAX;
        vector<long long> dist1(N + 1, INF), dist2(N + 1, INF);


        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist1[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist2[u]) continue;

            for (auto &[v, w] : adj[u])
            {
                long long nd = d + w;

                if (nd < dist1[v])
                {
                    dist2[v] = dist1[v];
                    dist1[v] = nd;
                    pq.push({nd, v});
                }
                else if (nd > dist1[v] && nd < dist2[v])
                {
                    dist2[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        cout << "Case " << tc << ": " << dist2[N] << "\n";
    }

    return 0;
}

