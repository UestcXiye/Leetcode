#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int bit = n & 01;
    if (bit)
        bit = 0;
    else
        bit = 1;
    // cout << "bit: " << bit << endl;
    while (n)
    {
        cout << ((n & 01) ^ bit) << endl;
        if (bit)
            bit = 0;
        else
            bit = 1;
        n >>= 1;
    }

    system("pause");
    return 0;
}
