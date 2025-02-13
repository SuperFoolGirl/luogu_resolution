// 1. dfs 超时
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct PairHash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const
    {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second); // 调用hash类的()重载函数 就是求哈希值 然后通过异或合并
    }
};

pair<int, int> B, horse;
int horseX[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int horseY[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {1, 0};
int dy[] = {0, 1};
unordered_set<pair<int, int>, PairHash> ctrls; // 需要给哈希函数
int ans = 0;

void dfs(int x, int y)
{
    if (x == B.first && y == B.second)
        ans++;

    for (int i = 0; i < 2; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX > B.first || nextY < 0 || nextY > B.second)
            continue;

        if (ctrls.count({nextX, nextY}))
            continue;

        dfs(nextX, nextY);
    }
}

int main()
{
    cin >> B.first >> B.second >> horse.first >> horse.second;
    for (int i = 0; i < 9; i++)
        ctrls.insert({horse.first + horseX[i], horse.second + horseY[i]});
    dfs(0, 0);
    cout << ans;
    return 0;
}



// 2. dp 注意数据爆int
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct PairHash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const
    {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second); // 调用hash类的()重载函数 就是求哈希值 然后通过异或合并
    }
};

int main()
{
    vector<vector<long long>> dp(21, vector<long long>(21, 0)); // dp[i][j] 表示从(0, 0)到(i, j)的路径数

    pair<int, int> B, horse;
    int horseX[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
    int horseY[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    unordered_set<pair<int, int>, PairHash> ctrls; // 需要给哈希函数

    cin >> B.first >> B.second >> horse.first >> horse.second;

    for (int i = 0; i < 9; i++)
        ctrls.insert({horse.first + horseX[i], horse.second + horseY[i]});

    dp[0][0] = 1;
    for (int i = 0; i <= B.first; i++)
    {
        for (int j = 0; j <= B.second; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (ctrls.count({i, j}))
                continue;

            if (i != 0)
                dp[i][j] += dp[i - 1][j];

            if (j != 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[B.first][B.second];
    return 0;
}