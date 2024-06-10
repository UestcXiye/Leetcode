/*
 * @lc app=leetcode.cn id=3177 lang=cpp
 *
 * [3177] 求出最长好子序列 II
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> fs;
        vector<array<int, 3>> records(k + 1);
        for (int x : nums)
        {
            if (!fs.contains(x))
            {
                fs[x] = vector<int>(k + 1);
            }
            auto &f = fs[x];
            for (int j = k; j >= 0; j--)
            {
                f[j]++;
                if (j)
                {
                    auto &r = records[j - 1];
                    int mx = r[0], mx2 = r[1], num = r[2];
                    f[j] = max(f[j], (x != num ? mx : mx2) + 1);
                }

                // records[j] 维护 fs[.][j] 的 mx, mx2, num
                int v = f[j];
                auto &p = records[j];
                if (v > p[0])
                {
                    if (x != p[2])
                    {
                        p[2] = x;
                        p[1] = p[0];
                    }
                    p[0] = v;
                }
                else if (x != p[2] && v > p[1])
                {
                    p[1] = v;
                }
            }
        }
        return records[k][0];
    }
};
// @lc code=end
