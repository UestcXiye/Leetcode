#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string transToMax(string s)
{
    string temp = s;
    int index = 0;
    while (s[index] == '9')
        index++;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == s[index])
            temp[i] = '9';
    return temp;
}

string transToMin(string s)
{
    string temp = s;
    char c = s[0];
    for (int i = 0; i < s.size(); i++)
        if (s[i] == c)
            temp[i] = '0';
    return temp;
}

int strToNum(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum = 10 * sum + s[i] - '0';
    return sum;
}

int main()
{
    cout << strToNum("123") << endl;
    cout << transToMax("11891") << endl;
    cout << transToMin("11891") << endl;

    system("pause");
    return 0;
}
