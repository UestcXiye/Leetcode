/*
 * @lc app=leetcode.cn id=3044 lang=cpp
 *
 * [3044] 出现频率最高的质数
 */

// @lc code=start
class Solution
{
private:
    const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    const int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};

public:
    int mostFrequentPrime(vector<vector<int>> &mat)
    {
        if (mat.empty())
            return 0;

        int m = mat.size(), n = m ? mat[0].size() : 0;

        unordered_map<int, int> cnt;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 8; k++)
                {
                    int r = i + dx[k], c = j + dy[k], v = mat[i][j];
                    // 只统计大于 10 的质数
                    // if (isPrime(v))
                    //     cnt[v]++;
                    while (r >= 0 && r < m && c >= 0 && c < n)
                    {
                        v = 10 * v + mat[r][c];
                        if (isPrime(v))
                            cnt[v]++;
                        r += dx[k];
                        c += dy[k];
                    }
                }

        int ans = -1, maxCount = 0;
        for (auto &[num, count] : cnt)
        {
            if (count > maxCount)
            {
                ans = num;
                maxCount = count;
            }
            else if (count == maxCount)
                ans = max(ans, num);
        }
        return ans;
    }
    // 辅函数 - 判断数字 n 是否是质数
    bool isPrime(int n)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
