#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int sum = 0;
    int num = 28;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i * i < num)
                sum += num / i;
        }
    }

    system("pause");
    return 0;
}
