// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
// Bicoloring problem in Onlinejudge

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int l;
        cin >> l;

        vector<vector<int>> adj(n);
        for (int i = 0; i < l; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> color(n, -1);
        bool flag = true;


        queue<int> q;
        q.push(0);
        color[0] = 0;

        while (!q.empty() && flag)
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}

