/*
 * @lc app=leetcode.cn id=3116 lang=cpp
 *
 * [3116] 单面值组合的第 K 小金额
 */

// @lc code=start

// 容斥原理 + 二分答案

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        auto check = [&](long long m) -> bool
        {
            long long cnt = 0;
            // 枚举所有非空子集
            for (int i = 1; i < (1 << coins.size()); i++)
            {
                long long lcm_res = 1; // 计算子集 LCM
                for (int j = 0; j < coins.size(); j++)
                {
                    if ((i >> j) & 0x1)
                    {
                        lcm_res = lcm(lcm_res, coins[j]);
                        if (lcm_res > m)
                        { // 太大了
                            break;
                        }
                    }
                }
                cnt += __builtin_popcount(i) % 2 ? m / lcm_res : -m / lcm_res;
            }
            return cnt >= k;
        };

        long long left = k - 1, right = (long long)ranges::min(coins) * k;
        while (left + 1 < right)
        {
            long long mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};
// @lc code=end
