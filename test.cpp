#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {10, 4, 8, 3};
    int n = nums.size();
    vector<int> leftSum(n);
    vector<int> rightSum(n);
    leftSum[0] = 0;
    for (int i = 1; i < n; i++)
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    // for (int i = 0; i < n; i++)
    //     cout << leftSum[i] << " ";
    // cout << endl;
    rightSum[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    // for (int i = 0; i < n; i++)
    //     cout << rightSum[i] << " ";
    // cout << endl;

    system("pause");
    return 0;
}
