/*
 * @lc app=leetcode.cn id=3016 lang=cpp
 *
 * [3016] 输入单词需要的最少按键次数 II
 */

// @lc code=start
class Solution
{
public:
    int minimumPushes(string word)
    {
        // 特判
        if (word.empty())
            return 0;

        int n = word.size();
        vector<int> alpha(26, 0);
        for (char &c : word)
            alpha[c - 'a']++;
        sort(alpha.begin(), alpha.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += alpha[i] * (i / 8 + 1);
        return ans;
    }
};
// @lc code=end
