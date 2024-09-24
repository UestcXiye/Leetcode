/*
 * @lc app=leetcode.cn id=3289 lang=cpp
 *
 * [3289] 数字小镇中的捣蛋鬼
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (int &num : nums)
            cnt[num]++;
        vector<int> ans;
        for (auto &[num, c] : cnt)
            if (c == 2)
                ans.push_back(num);
        return ans;
    }
};
// @lc code=end
