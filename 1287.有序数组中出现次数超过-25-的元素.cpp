/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        if (arr.size() == 1)
            return arr[0];
        int distance = arr.size() / 4 + 1, ans = 0;
        for (int i = 0; i < arr.size() - distance + 1; i++)
            if (arr[i] == arr[i + distance - 1])
            {
                ans = arr[i];
                break;
            }
        return ans;
    }
};
// @lc code=end
