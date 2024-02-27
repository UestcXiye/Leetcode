/*
 * @lc app=leetcode.cn id=3046 lang=cpp
 *
 * [3046] 分割数组
 */

// @lc code=start
class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (int &x : nums)
            cnt[x]++;
            
        for (auto &[x, count] : cnt)
            if (count > 2)
                return false;
        return true;
    }
};
// @lc code=end
