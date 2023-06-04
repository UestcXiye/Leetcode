/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        if (k > 0)
        {
            vector<int> ans(n);
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = 1; j <= k; j++)
                    sum += code[(i + j) % n];
                ans[i] = sum;
            }
            return ans;
        }
        else if (k < 0)
        {
            vector<int> ans(n);
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = 1; j <= abs(k); j++)
                    sum += code[(n + i - j) % n];
                ans[i] = sum;
            }
            return ans;
        }
        else
            return vector<int>(n, 0);
    }
};
// @lc code=end
