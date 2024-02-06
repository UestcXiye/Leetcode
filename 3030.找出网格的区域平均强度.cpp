/*
 * @lc app=leetcode.cn id=3030 lang=cpp
 *
 * [3030] 找出网格的区域平均强度
 */

// @lc code=start

// 模拟

class Solution
{
public:
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {
        int m = image.size(), n = m ? image[0].size() : 0;
        vector<vector<int>> result(m, vector<int>(n, 0));
        vector<vector<int>> cnt(m, vector<int>(n, 0));

        for (int i = 2; i < m; i++)
        {
            for (int j = 2; j < n; j++)
            {
                // 检查左右相邻格子
                bool ok = true;
                for (int x = i - 2; x <= i; x++)
                {
                    if (abs(image[x][j - 2] - image[x][j - 1]) > threshold ||
                        abs(image[x][j - 1] - image[x][j]) > threshold)
                    {
                        ok = false;
                        break; // 不合法，下一个
                    }
                }
                if (!ok)
                    continue;

                // 检查上下相邻格子
                for (int y = j - 2; y <= j; y++)
                {
                    if (abs(image[i - 2][y] - image[i - 1][y]) > threshold ||
                        abs(image[i - 1][y] - image[i][y]) > threshold)
                    {
                        ok = false;
                        break; // 不合法，下一个
                    }
                }
                if (!ok)
                    continue;

                // 合法，计算 3x3 子网格的平均值
                int avg = 0;
                for (int x = i - 2; x <= i; x++)
                    for (int y = j - 2; y <= j; y++)
                        avg += image[x][y];
                avg /= 9;

                // 更新 3x3 子网格内的 result
                for (int x = i - 2; x <= i; x++)
                    for (int y = j - 2; y <= j; y++)
                    {
                        result[x][y] += avg; // 先累加，最后再求平均值
                        cnt[x][y]++;
                    }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (cnt[i][j] == 0)
                {
                    // (i,j) 不属于任何子网格
                    result[i][j] = image[i][j];
                }
                else
                {
                    // 求平均值
                    result[i][j] /= cnt[i][j];
                }
            }
        return result;
    }
};
// @lc code=end
