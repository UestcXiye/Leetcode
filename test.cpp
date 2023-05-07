#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string trans(int n)
{
    string result = "";
    while (n > 0)
    {
        result += '0' + n % 2;
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int x = 1, y = 4;
    string sx = trans(x);
    string sy = trans(y);
    int ans = 0;
    int i = sx.size() - 1;
    int j = sy.size() - 1;
    while (i >= 0 || j >= 0)
    {
        char item_x = i >= 0 ? sx[i] : '0';
        char item_y = j >= 0 ? sy[j] : '0';
        if (item_x != item_y)
            ans++;
        i--;
        j--;
    }
    cout << ans << endl;

    system("pause");
    return 0;
}
