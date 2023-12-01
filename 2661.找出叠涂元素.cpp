/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start
class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        if (arr.empty() || mat.empty())
            return -1;
        int m = mat.size(), n = m ? mat[0].size() : 0;
        unordered_map<int, pair<int, int>> hash; // <整数，pair<横坐标，纵坐标>>
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int key = mat[i][j];
                pair<int, int> value(i, j);
                hash[key] = value;
            }
        vector<int> rowsCount(m, 0), colsCount(n, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            int row = hash[arr[i]].first, col = hash[arr[i]].second;
            rowsCount[row]++;
            if (rowsCount[row] == n)
                return i;
            colsCount[col]++;
            if (colsCount[col] == m)
                return i;
        }
        return -1;
    }
};
// @lc code=end
