/*
 * @lc app=leetcode.cn id=3331 lang=cpp
 *
 * [3331] 修改后子树的大小
 */

// @lc code=start
class Solution
{
public:
    vector<int> findSubtreeSizes(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<int> newParent(n, 1);

        // 建立新树
        for (int i = 0; i < n; i++)
        {
            int t = parent[i];
            while (t != -1 && s[t] != s[i])
                t = parent[t];

            if (t != -1 && s[i] == s[t])
                newParent[i] = t;
            else
                newParent[i] = parent[i];
        }

        // 统计子树大小
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            int t = newParent[i];
            while (t != -1)
            {
                ans[t]++;
                t = newParent[t];
            }
        }

        return ans;
    }
};
// @lc code=end
