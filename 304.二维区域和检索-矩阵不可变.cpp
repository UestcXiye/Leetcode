/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix
{
private:
    vector<vector<int>> integral;

public:
    NumMatrix(vector<vector<int>> matrix)
    {
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
        integral = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                integral[i][j] = matrix[i - 1][j - 1] + integral[i - 1][j] + integral[i][j - 1] - integral[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return integral[row2 + 1][col2 + 1] - integral[row2 + 1][col1] - integral[row1][col2 + 1] + integral[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
