#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

string turnToBits(int num)
{
    string bits;
    while (num)
    {
        bits.push_back(num % 2 + '0');
        num /= 2;
    }
    return bits;
}

int main()
{
    int start = 10, goal = 82;
    string startBits = turnToBits(start);
    string goalBits = turnToBits(goal);
    if (startBits.size() < goalBits.size())
        startBits.append(goalBits.size() - startBits.size(), '0');
    else
        goalBits.append(startBits.size() - goalBits.size(), '0');
    cout << startBits << endl;
    cout << goalBits << endl;
    system("pause");
    return 0;
}
