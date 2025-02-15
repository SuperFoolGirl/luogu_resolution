#include <iostream>
#include <vector>
using namespace std;

// 最大公约数
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 最小公倍数
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int x, y;
    cin >> x >> y;
    int ans = 0;

    // 只遍历 x 的倍数
    for (int a = x; a <= y; a += x)
    {
        if (y % a != 0)
            continue; // 如果y不能被a整除，跳过。因为y必须是a的最小公倍数

        // 这里很关键。我之前的想法是遍历出b来，但是这样会导致时间复杂度过高
        int b = x * y / a; // 直接尝试计算b：根据lcm函数 ab=ab最小公倍数*ab最大公约数。这里得出来的b必然<=y

        // 讲一下这里增加答案的逻辑
        // 1. 若ab不相同
        // 若a<b，那么会先后遍历到ab。ans++两次，正好把正反两种答案算上
        // 2. 若ab相同
        // 若a=b，那么只会遍历到ab一次。ans++一次，只算上一种答案
        if (gcd(a, b) == x && lcm(a, b) == y)
            ans++;
    }

    cout << ans << endl;

    return 0;
}