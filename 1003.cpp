// 1. MLE
// 用哈希表都没救回来
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, unordered_map<int, int>> ground;
    int a, b, g, k, n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> g >> k;
        for (int j = a; j < a + g; j++)
            for (int l = b; l < b + k; l++)
                ground[j][l] = i;
    }
    cin >> x >> y;
    if (ground[x][y])
        cout << ground[x][y];
    else
        cout << -1;
    return 0;
}



// 2. 改进思路 遍历毯子
#include <iostream>
using namespace std;

int main()
{
    int n, x, y, ans = -1;
    cin >> n;
    int a[n + 1], b[n + 1], g[n + 1], k[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
        if (x >= a[i] && x < a[i] + g[i] && y >= b[i] && y < b[i] + k[i])
            ans = i;
    cout << ans;
    return 0;
}