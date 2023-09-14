/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> hash; //<值，出现次数>
        for (int &num : nums)
        {
            hash[num]++;
            if (hash[num] >= 2)
                return true;
        }
        return false;
    }
};
// @lc code=end
