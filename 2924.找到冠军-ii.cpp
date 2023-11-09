/*
 * @lc app=leetcode.cn id=2924 lang=cpp
 *
 * [2924] 找到冠军 II
 */

// @lc code=start
class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> isChampion(n, true);
        for (const vector<int> &edge : edges)
            isChampion[edge[1]] = false;
        int ans = -1;
        for (int i = 0; i < n; i++)
            if (isChampion[i])
            {
                if (ans != -1)
                    return -1;
                ans = i;
            }
        return ans;
    }
};
// @lc code=end
