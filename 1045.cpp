// 待修改
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 高精度乘法
vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(a.size() + b.size(), 0);
    // 一次双重循环直接跑完，学一下写法
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            result[i + j] += a[i] * b[j];
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
    // 去除前导零
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }
    return result;
}

// 高精度快速幂
vector<int> fast_pow(const vector<int> &a, int n)
{
    vector<int> result = {1};
    vector<int> current = a;
    while (n > 0)
    {
        if (n & 1)
        {
            result = multiply(result, current);
        }
        current = multiply(current, current);
        n >>= 1;
    }
    return result;
}

// 打印高精度结果
void print(const vector<int> &num)
{
    for (int i = 499; i >= num.size(); i--)
        cout << 0;

    for (int i = num.size() - 1; i >= 1; --i)
    {
        cout << num[i];
    }
    cout << num[0] - 1;
}

int main()
{
    int p;
    cin >> p;

    vector<int> base;
    base.push_back(2);

    vector<int> result = fast_pow(base, p);
    print(result);

    return 0;
}