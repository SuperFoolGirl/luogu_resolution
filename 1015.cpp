// 高精度+进制转换+回文

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
string m;
vector<int> num;
vector<int> sum;

void convert_string_to_int(string m)
{
    int len = m.length();
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
    {
        if (m[i] >= '0' && m[i] <= '9')
            num.push_back(m[i] - '0');
        else
            num.push_back(m[i] - 'A' + 10);
    }
}

void add()
{
    int len = num.size();
    sum.resize(len + 1);
    for (int i = 0, j = len - 1; i < len; i++, j--)
    {
        sum[i] += num[i] + num[j];
        sum[i + 1] = sum[i] / n;
        sum[i] %= n;
    }
    while (sum.back() == 0)
        sum.pop_back();

    num = sum;
    sum.clear();
}

bool check()
{
    int len = num.size();
    for (int i = 0, j = len - 1; i <= j; i++, j--)
    {
        if (num[i] != num[j])
            return true;
    }
    return false;
}

int main()
{
    cin >> n;
    cin >> m;
    // 把每一位转化成数字
    // 但注意 这里并不是转为十进制
    // 并不是只有十进制才能参与计算！
    convert_string_to_int(m);

    int times = 0;
    do
    {
        add();
        times++;
    } while (check() && times <= 30);

    if (times <= 30)
        cout << "STEP=" << times;
    else
        cout << "Impossible!";

    return 0;
}