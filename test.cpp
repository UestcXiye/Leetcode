#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j < n; j++)
            if (isPrime(j) && isPrime(i - j))
            {
                cout << i << "=" << j << "+" << i - j << endl;
                break;
            }
    }

    system("pause");
    return 0;
}
