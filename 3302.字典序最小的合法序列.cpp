/*
 * @lc app=leetcode.cn id=3302 lang=cpp
 *
 * [3302] 字典序最小的合法序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        vector<int> suf(n + 1);
        suf[n] = m;
        for (int i = n - 1, j = m - 1; i >= 0; i--)
        {
            if (j >= 0 && word1[i] == word2[j])
                j--;
            suf[i] = j + 1;
        }

        vector<int> ans(m);
        bool changed = false; // 是否修改过
        for (int i = 0, j = 0; i < n; i++)
        {
            if (word1[i] == word2[j] || !changed && suf[i + 1] <= j + 1)
            {
                if (word1[i] != word2[j])
                    changed = true;
                ans[j++] = i;
                if (j == m)
                    return ans;
            }
        }
        return {};
    }
};
// @lc code=end
