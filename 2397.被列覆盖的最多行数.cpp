/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start

// 二进制枚举

// class Solution
// {
// public:
//     int maximumRows(vector<vector<int>> &matrix, int numSelect)
//     {
//         // 特判
//         if (matrix.empty())
//             return 0;
//         int m = matrix.size(), n = m ? matrix[0].size() : 0;
//         vector<int> masks(m, 0); // 存储每一行的数字掩码
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//             {
//                 // 生成数字掩码，将第 j 个数字添加到 mask 从左往右的第 j 位
//                 masks[i] |= (matrix[i][j] << (n - j - 1));
//             }
//         int maxRows = 0;
//         int cur = 0;
//         while ((++cur) < (1 << n))
//         {
//             if (__builtin_popcount(cur) != numSelect)
//                 continue;
//             int coverRows = 0;
//             for (int i = 0; i < m; i++)
//                 if ((masks[i] & cur) == 0)
//                     coverRows++;
//             maxRows = max(maxRows, coverRows);
//         }
//         return maxRows;
//     }
// };

// 回溯 + 位运算

class Solution
{
private:
    int maxRows = 0;

public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        // 特判
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<int> masks(m, 0); // 存储每一行的数字掩码
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                // 生成数字掩码，将第 j 个数字添加到 mask 从右往左的第 j 位
                masks[i] |= (matrix[i][j] << j);
            }
        int s = 0;
        backtracking(masks, numSelect, 0, n, s);
        return maxRows;
    }
    /**
     * @brief 辅函数 - 回溯，对当前 index 列有选与不选两种选择
     * @param masks: 每一行的数字掩码
     * @param numSelect: 当前还可以选择的列数
     * @param index：当前处理的列索引
     * @param n: 总列数，也是列索引上界
     * @param s: 选择的列集合掩码
     */
    void backtracking(vector<int> &masks, int numSelect, int index, int n, int s)
    {
        if (numSelect == 0)
        {
            int coverRows = 0;
            for (int &mask : masks)
            {
                // mask & ~s：如果选择的列在该行为 1，置为 0
                if ((mask & ~s) == 0)
                {
                    // 如果结果为 0，说明当前行所有列都为 0，该行被覆盖，行数 +1
                    coverRows++;
                }
            }
            // 更新最大覆盖行数
            maxRows = max(maxRows, coverRows);
            return;
        }
        // 列索引到达上界，直接返回
        if (index == n)
            return;
        // 不选当前列
        backtracking(masks, numSelect, index + 1, n, s);
        // 选择当前列，将当前列在 s 中的对应位置 1
        s |= (1 << index);
        // 选择当前列
        backtracking(masks, numSelect - 1, index + 1, n, s);
    }
};
// @lc code=end
