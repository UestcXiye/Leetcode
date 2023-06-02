/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        vector<int> alpha(26, 0);
        for (char &c : allowed)
            alpha[c - 'a'] = 1;
        int ans = 0;
        for (string &word : words)
        {
            bool judge = true;
            for (char &c : word)
                if (alpha[c - 'a'] == 0)
                {
                    judge = false;
                    break;
                }
            if (judge)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
