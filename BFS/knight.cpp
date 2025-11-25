// Knight moves problem in Onlinejudge

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
    int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

    string st1, st2;
    while (cin >> st1 >> st2) {
        int sr = st1[1] - '1';
        int sc = st1[0] - 'a';
        int tr = st2[1] - '1';
        int tc = st2[0] - 'a';


        int d[8][8];
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                d[i][j] = -1;

        d[sr][sc] = 0;

        queue<pair<int,int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            if (r == tr && c == tc) break;

            for (int k = 0; k < 8; ++k) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (nr >= 0 && nc >= 0 && nr < 8 && nc < 8 && d[nr][nc] == -1) {
                    d[nr][nc] = d[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        cout << "To get from " << st1 << " to " << st2 << " takes "
             << d[tr][tc] << " knight moves\n";
    }

    return 0;
}

