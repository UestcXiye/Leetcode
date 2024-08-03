/*
 * @lc app=leetcode.cn id=3223 lang=cpp
 *
 * [3223] 操作后字符串的最短长度
 */

// @lc code=start
class Solution
{
public:
    int minimumLength(string s)
    {
        unordered_map<char, int> freq;
        for (char &c : s)
            freq[c]++;

        int ans = 0;
        for (auto &[c, cnt] : freq)
            ans += cnt % 2 ? 1 : 2;
        return ans;
    }
};
// @lc code=end
