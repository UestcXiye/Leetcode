/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start

// 前缀和 + 二分查找

class Solution
{
    vector<int> sums;

public:
    Solution(vector<int> weights) : sums(std::move(weights))
    {
        // 使用 partial_sum 求前缀和
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }

    // 每当需要采样时，我们可以先随机产生一个数字，
    // 然后使用二分法查找其在前缀和中的位置，以模拟加权采样的过程
    int pickIndex()
    {
        int pos = (rand() % sums.back()) + 1;
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
