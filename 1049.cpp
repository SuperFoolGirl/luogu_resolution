// 常规01背包
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int v, n;
    vector<int> volume;
    cin >> v;
    cin >> n;
    vector<int> dp(v + 2);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        volume.push_back(input);
    }

    for (int i = 0; i < n; i++)
        for (int j = v; j >= volume[i]; j--)
            dp[j] = max(dp[j], dp[j - volume[i]] + volume[i]);

    cout << v - dp[v] << endl;
    return 0;
}