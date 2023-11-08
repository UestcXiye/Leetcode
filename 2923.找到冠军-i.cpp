/*
 * @lc app=leetcode.cn id=2923 lang=cpp
 *
 * [2923] 找到冠军 I
 */

// @lc code=start
class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> isChampion(n, true);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    isChampion[j] = false;
        for (int i = 0; i < n; i++)
            if (isChampion[i])
                return i;
        return -1;
    }
};
// @lc code=end
