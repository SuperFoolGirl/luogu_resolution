// 一开始没看出来 其实这是连通块问题
// 我们找出联通块来，然后把联通块的所有点都标记为联通块的大小
// 连通块内的点互相可达，所以记录在dist里的值相同

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> map;
vector<vector<bool>> vis;
vector<vector<int>> dist;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

// 广度优先搜索函数，计算从 (x, y) 出发能到达的格子数
void bfs(int x, int y)
{
    vector<pair<int, int>> connected; // 用于记录当前连通块的所有可达点
    q.push({x, y});
    vis[x][y] = true;
    int count = 0; // 记录可达格子数

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        connected.push_back(t);
        count++;

        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 0 || a >= n || b < 0 || b >= n)
                continue;
            if (vis[a][b])
                continue;
            if (map[a][b] == map[t.first][t.second])
                continue;

            vis[a][b] = true;
            q.push({a, b});
        }
    }

    // 将当前连通块的所有可达点标记为相同的可达格子数
    for (auto &p : connected)
    {
        dist[p.first][p.second] = count;
    }
}

int main()
{
    cin >> n >> m;
    vis.resize(n, vector<bool>(n, false));
    dist.resize(n, vector<int>(n, 0));
    map.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    // 遍历所有格子，对未访问过的格子进行 BFS
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x - 1][y - 1] << endl;
    }

    return 0;
}