/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int distance = 0;
        for (const int &x : arr1)
        {
            int count = 0;
            for (const int &y : arr2)
                if (abs(x - y) > d)
                    count++;
            if (count == arr2.size())
                distance++;
        }
        return distance;
    }
};
// @lc code=end
