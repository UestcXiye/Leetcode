/*
 * @lc app=leetcode.cn id=3015 lang=cpp
 *
 * [3015] 按距离统计房屋对数目 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<int> ans(n, 0);
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                int len1 = j - i;                       // i->j
                int len2 = abs(i - x) + 1 + abs(j - y); // i->x->y->j
                int len3 = abs(i - y) + 1 + abs(j - x); // i->y->x->j
                // 取最短距离作为路径
                int len = min({len1, len2, len3});
                ans[len - 1] += 2; // 路径是双向的
            }
        return ans;
    }
};
// @lc code=end
