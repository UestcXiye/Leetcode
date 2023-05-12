/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        set<int> s;
        for (int num : nums)
        {
            if (num)
                s.insert(num);
        }
        return s.size();
    }
};
// @lc code=end
