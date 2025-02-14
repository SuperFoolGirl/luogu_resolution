// 阶乘之和 算是一生之耻了 期末上机没写出来
// 这一次的处理其实也不太乐观 很多细节没处理好
// 注意数组变量的设置
// 最关键的是数组的清空 搞清楚哪些数组是中间变量，需要清空

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result; // 储存(n-1)!*n的进位，并最终展开为n!。但由于其起到中间变量的作用，所以需要清空。因此后续选择将result赋给tmp2，使其完成add步骤
vector<int> sum;    // 储存阶乘之和
vector<int> tmp1;   // 储存n的每一位
vector<int> tmp2;   // 储存(n-1)!的每一位

// 将n拆成数组
void arrange(int x)
{
    tmp1.clear();
    while (x)
    {
        tmp1.push_back(x % 10);
        x /= 10;
    }
}

// 计算n*(n-1)!
void multiply()
{
    int lena = tmp1.size();
    int lenb = tmp2.size();
    int len = lena + lenb;
    result.resize(lena + lenb, 0);

    for (int i = 0; i < lena; i++)
        for (int j = 0; j < lenb; j++)
            result[i + j] += tmp1[i] * tmp2[j];
    for (int i = 0; i < len; i++)
    {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    // 把n!的结果存到tmp2中，以便下次算(n+1)!
    // 注意result必须清空
    tmp2 = result;
    result.clear();
}

// 计算sum+=tmp2(tmp2被附了result的值，即n!)
void add()
{
    int a = sum.size();
    int b = tmp2.size();
    int len = max(a, b);
    sum.resize(len + 1, 0);
    // 由于sum本来就储存数，所以需要全部加等
    for (int i = 0; i < len; i++)
    {
        // tmp2没有扩容 不加这一句会越界
        if (i < tmp2.size())
            sum[i] += tmp2[i];
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }

    while (sum.size() > 1 && sum.back() == 0)
        sum.pop_back();
}

void print()
{
    for (int i = sum.size() - 1; i >= 0; i--)
        cout << sum[i];
}

int main()
{
    int n;
    cin >> n;
    tmp2.push_back(1);

    for (int i = 1; i <= n; i++)
    {
        arrange(i);
        multiply();
        add();
    }
    print();
    return 0;
}