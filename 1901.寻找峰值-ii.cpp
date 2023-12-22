/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start

// 二分查找

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        if (mat.empty())
            return {};
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = m - 1;
        while (left < right)
        {
            int i = (left + right) / 2;
            int j = indexOfRowMax(mat[i]);
            if (mat[i][j] > mat[i + 1][j])
                right = i; // 峰顶行号 <= i
            else
                left = i + 1; // 峰顶行号 > i
        }
        return {left, indexOfRowMax(mat[left])};
    }
    // 辅函数 - 返回行中最大元素的下标
    int indexOfRowMax(const vector<int> &row)
    {
        return max_element(row.begin(), row.end()) - row.begin();
    }
};
// @lc code=end
