/*
 * @lc app=leetcode.cn id=3334 lang=cpp
 *
 * [3334] 数组的最大因子得分
 */

// @lc code=start
class Solution
{
public:
    long long maxScore(vector<int> &nums)
    {
        int n = nums.size();
        
        // pre_gcd 存储从前往后的最大公约数，初始化为1
        vector<int> pre_gcd(n);
        // pre_lcm 存储从前往后的最小公倍数，初始化为1
        vector<long long> pre_lcm(n);
        // 初始化第一个位置的最小公倍数为 nums[0]
        pre_lcm[0] = nums[0];
        pre_gcd[0] = nums[0];
        // 从前往后计算前缀的最大公约数和最小公倍数
        for (int i = 1; i < n; i++)
        {
            pre_gcd[i] = gcd(pre_gcd[i - 1], nums[i]);
            pre_lcm[i] = lcm(pre_lcm[i - 1], nums[i]);
        }

        // suf_gcd 存储从后往前的最大公约数，初始化为1
        vector<int> suf_gcd(n + 1);
        // suf_lcm 存储从后往前的最小公倍数，初始化为1
        vector<long long> suf_lcm(n + 1);
        // 初始化最后一个位置的最小公倍数为 1
        suf_lcm[n] = 1;
        // 从后往前计算后缀的最大公约数和最小公倍数
        for (int i = n - 1; i >= 0; i--)
        {
            suf_gcd[i] = gcd(suf_gcd[i + 1], nums[i]);
            suf_lcm[i] = lcm(suf_lcm[i + 1], nums[i]);
        }

        // 先计算不移除任何元素时的因子得分，即整个数组的前缀最大公约数和最小公倍数的乘积
        long long ans = suf_gcd[0] * suf_lcm[0];
        // 枚举移除每个元素 nums[i]
        for (int i = 0; i < n; i++)
        {
            // 当移除 nums[0] 时，只需考虑后缀的最大公约数和最小公倍数
            if (i == 0)
                ans = max(ans, suf_gcd[1] * suf_lcm[1]);
            // 当移除 nums[n-1] 时，只需考虑前缀的最大公约数和最小公倍数
            else if (i == n - 1)
                ans = max(ans, pre_gcd[n - 2] * pre_lcm[n - 2]);
            // 移除其他元素时，计算前缀和后缀的最大公约数和最小公倍数的乘积
            else
                ans = max(ans, gcd(pre_gcd[i - 1], suf_gcd[i + 1]) * lcm(pre_lcm[i - 1], suf_lcm[i + 1]));
        }
        // 返回最大因子得分
        return ans;
    }
};
// @lc code=end
