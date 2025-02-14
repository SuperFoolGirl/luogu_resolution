#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int used[10] = {0};

bool check(int x)
{
    while (x)
    {
        used[x % 10]++;
        if (used[x % 10] > 1)
            return false;
        // 不能出现0 这一点容易忽略
        if (used[0] > 0)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    vector<int> ans;
    int start = 192;
    int a, b, c;
    for (int i = start; i < 333; i++)
    {
        memset(used, 0, sizeof(used));
        a = i, b = 2 * i, c = 3 * i;
        if (check(a) && check(b) && check(c))
        {
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(c);
        }
    }
    // 学一下输出思路
    for (int i = 0; i < ans.size(); i += 3)
        cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << endl;

    return 0;
}