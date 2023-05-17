/*
 * @lc app=leetcode.cn id=2138 lang=cpp
 *
 * [2138] 将字符串拆分为若干长度为 k 的组
 */

// @lc code=start
class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> ans; // 分组后的字符串
        int n = s.size();
        int curr = 0; // 每个分组的起始下标
        // 拆分字符串
        while (curr < n)
        {
            ans.push_back(s.substr(curr, k));
            curr += k;
        }
        // 尝试填充最后一组
        ans.back() += string(k - ans.back().size(), fill);
        return ans;
    }
};
// @lc code=end
