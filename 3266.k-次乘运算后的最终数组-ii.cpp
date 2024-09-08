/*
 * @lc app=leetcode.cn id=3266 lang=cpp
 *
 * [3266] K 次乘运算后的最终数组 II
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;
    // 快速幂
    long long pow(long long x, int n)
    {
        long long res = 1;
        for (; n; n /= 2)
        {
            if (n % 2)
                res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        // 特判
        if (multiplier == 1)
            return move(nums);

        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<pair<long long, int>> h(n);
        for (int i = 0; i < n; i++)
        {
            h[i] = {nums[i], i};
        }
        ranges::make_heap(h, greater<>()); // 最小堆，O(n) 堆化

        // 模拟，直到堆顶是 mx
        for (; k && h[0].first < mx; k--)
        {
            ranges::pop_heap(h, greater<>());
            h.back().first *= multiplier;
            ranges::push_heap(h, greater<>());
        }

        // 剩余的操作可以直接用公式计算
        ranges::sort(h);
        for (int i = 0; i < n; i++)
        {
            auto &[x, j] = h[i];
            nums[j] = x % MOD * pow(multiplier, k / n + (i < k % n)) % MOD;
        }
        return move(nums);
    }
};
// @lc code=end
