#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> data;
    string s;
    while (cin >> s)
        data.push_back(s);

    int p1 = 0, p2 = 0;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].length(); j++)
        {
            if (data[i][j] == 'W')
                p1++;
            if (data[i][j] == 'L')
                p2++;
            if ((abs(p1 - p2) >= 2 && (p1 >= 11 || p2 >= 11)) || data[i][j] == 'E') // 左边是常规出口，右边是最后一次比分
            {
                cout << p1 << ":" << p2 << endl;
                p1 = 0;
                p2 = 0;

                if (data[i][j] == 'E')
                    break;
            }
        }
    }

    cout << endl;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].length(); j++)
        {
            if (data[i][j] == 'W')
                p1++;
            if (data[i][j] == 'L')
                p2++;
            if ((abs(p1 - p2) >= 2 && (p1 >= 21 || p2 >= 21)) || data[i][j] == 'E')
            {
                cout << p1 << ":" << p2 << endl;
                p1 = 0;
                p2 = 0;

                if (data[i][j] == 'E')
                    break;
            }
        }
    }
    return 0;
}