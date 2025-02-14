#include <iostream>
#include <cmath>
using namespace std;

void f(int n)
{
    for (int i = 14; i >= 0; i--)
    {
        if (n >= pow(2, i))
        {
            if (i == 0)
                cout << "2(0)";
            else if (i == 1)
                cout << "2";
            else
            {
                // 这里的两边括号的写法其实很有递归的味道
                cout << "2(";
                f(i); // 妙手
                cout << ")";
            }
            n -= pow(2, i);

            // 注意这个写加号的逻辑 非常合理而奇妙
            if (n != 0)
                cout << "+";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}