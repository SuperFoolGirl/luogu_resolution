// 1. dfs没记忆化搜索 tle
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans = 0;

void dfs(int stu, int times)
{
    if (times == m)
    {
        if (stu == 1)
            ans++;
        return;
    }

    if (stu == 1)
    {
        dfs(2, times + 1);
        dfs(n, times + 1);
    }
    else if (stu == n)
    {
        dfs(n - 1, times + 1);
        dfs(1, times + 1);
    }
    else
    {
        dfs(stu + 1, times + 1);
        dfs(stu - 1, times + 1);
    }
}

int main()
{
    cin >> n >> m;
    if (n == 1)
    { // 处理只有一个同学的特殊情况
        cout << 1;
        return 0;
    }
    dfs(1, 0); // 初始调用修正为0次传球
    cout << ans;
    return 0;
}



// 2. dp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j]表示第i次传球在j号位置的方案数
    dp[0][1] = 1; // 初始状态：0次传球在1号位置

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int left = (j == 1) ? n : j - 1;
            int right = (j == n) ? 1 : j + 1;
            dp[i][j] = dp[i - 1][left] + dp[i - 1][right];
        }
    }
    cout << dp[m][1];
    return 0;
}