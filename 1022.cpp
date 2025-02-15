// 我觉得写得真挺勾史的
// 主要掌握下string方法及stoi()函数的使用

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    char unknown;
    string equation;
    vector<int> num_left;     // 存储等式左边的数字
    vector<int> num_right;    // 存储等式右边的数字
    vector<int> factor_left;  // 存储等式左边的未知数的系数
    vector<int> factor_right; // 存储等式右边的未知数的系数
    vector<string> breaks_left;
    vector<string> breaks_right;
    double result_left = 0;
    double result_right = 0;
    double ans;

    cin >> equation;
    int pos_equ = equation.find('=');
    int pos = 0;

    // 找未知数
    for (int i = 0; i < equation.size(); i++)
    {
        if (equation[i] >= 'a' && equation[i] <= 'z')
        {
            unknown = equation[i];
            break;
        }
    }

    // 分割等式
    for (int i = 0; i < equation.size(); i++)
    {
        char c = equation[i];
        // 根据等号位置分割等式
        if (i <= pos_equ)
        {
            if ((c == '+' || c == '-' || c == '=') && i != 0) // 这里有坑 等式一开始就是负号的情况
            {
                breaks_left.push_back(equation.substr(pos, i - pos)); // 参数二为子串长度
                if (c == '=')
                    pos = i + 1;
                else
                    pos = i; // 更新pos为符号的位置 便于直接截取正负号
            }
        }
        else
        {
            if ((c == '+' || c == '-') && i != pos_equ + 1) // 这里有坑，等号后面的负号不应该被分割
            {
                breaks_right.push_back(equation.substr(pos, i - pos)); // 参数二为子串长度
                pos = i;                                               // 更新pos为符号的位置 便于直接截取正负号
            }
            if (i == equation.size() - 1)
                breaks_right.push_back(equation.substr(pos, i - pos + 1)); // 参数二为子串长度
        }
    }

    // 将左边转换为数字
    for (int i = 0; i < breaks_left.size(); i++)
    {
        // 讲一下stoi函数 非常强力的std库函数，比atoi更强大
        // 即使开头是正负号，也可以正常转换成对应数字 但只限正负号
        // 但无法处理"-"，如"-a"无法转换成数字"，而"-1"则可以直接转为-1
        // 遇到数字后如若遇到字母则停止转换，如“123a”只能转换成123

        // 1. 字母系数为1
        if (breaks_left[i].length() == 1 && breaks_left[i][0] == unknown)
        {
            factor_left.push_back(1);
            continue; // 用continue代替else的写法
        }

        // 2. 字母系数为-1
        if (breaks_left[i].length() == 2 && breaks_left[i][0] == '-' && breaks_left[i][1] == unknown)
        {
            factor_left.push_back(-1);
            continue;
        }

        // 3. 纯数字
        if (breaks_left[i].find(unknown) == string::npos)
        {
            num_left.push_back(stoi(breaks_left[i]));
            continue;
        }

        // 4. 最后一位是字母
        // 书写顺序很重要 这个会和2冲突，但先判断为2后再判断4就没问题了
        if (breaks_left[i].back() == unknown)
        {
            factor_left.push_back(stoi(breaks_left[i])); // stoi函数只能处理数字，所以这里不会出错
            continue;
        }
    }

    // 将右边转换为数字
    for (int i = 0; i < breaks_right.size(); i++)
    {
        if (breaks_right[i].length() == 1 && breaks_right[i].front() == unknown)
        {
            factor_right.push_back(1);
            continue;
        }

        if (breaks_right[i].length() == 2 && breaks_right[i].front() == '-' && breaks_right[i].back() == unknown)
        {
            factor_right.push_back(-1);
            continue;
        }

        if (breaks_right[i].find(unknown) == string::npos)
        {
            num_right.push_back(stoi(breaks_right[i]));
            continue;
        }

        if (breaks_right[i].back() == unknown)
        {
            factor_right.push_back(stoi(breaks_right[i]));
            continue;
        }
    }

    // 计算结果 左边是字母系数 右边是数字
    // 1. 计算字母系数
    for (auto i : factor_left)
        result_left += i;
    for (auto i : factor_right)
        result_left -= i;

    // 2. 计算数字
    for (auto i : num_left)
        result_right -= i;
    for (auto i : num_right)
        result_right += i;

    // 3. 计算结果
    if (fabs(result_right) < 1e-4)
        cout << unknown << "=0.000" << endl; // 防止-0.000的情况
    else
    {
        ans = result_right / result_left;
        printf("%c=%.3lf\n", unknown, ans);
    }
    return 0;
}