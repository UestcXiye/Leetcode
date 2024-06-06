/*
 * @lc app=leetcode.cn id=3170 lang=cpp
 *
 * [3170] 删除星号以后字典序最小的字符串
 */

// @lc code=start
class Solution
{
public:
    string clearStars(string s)
    {
        int n = s.length();
        stack<int> idx[26];
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
            {
                idx[s[i] - 'a'].push(i);
                continue;
            }
            // 遇到 *
            for (auto &stk : idx)
            {
                if (!stk.empty())
                {
                    s[stk.top()] = '*';
                    stk.pop();
                    break;
                }
            }
        }
        
        string ans;
        for (char &c : s)
            if (c != '*')
                ans.push_back(c);
        return ans;
    }
};
// @lc code=end
