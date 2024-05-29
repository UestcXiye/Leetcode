/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 *
 * [3165] 不包含相邻元素的子序列的最大和
 */

// @lc code=start
class Solution
{
    // 4 个数分别保存 f00, f01, f10, f11
    vector<array<unsigned int, 4>> t;

    void maintain(int o)
    {
        auto &a = t[o * 2], b = t[o * 2 + 1];
        t[o] = {
            max(a[0] + b[2], a[1] + b[0]),
            max(a[0] + b[3], a[1] + b[1]),
            max(a[2] + b[2], a[3] + b[0]),
            max(a[2] + b[3], a[3] + b[1]),
        };
    }

    // 用 nums 初始化线段树
    void build(vector<int> &nums, int o, int l, int r)
    {
        if (l == r)
        {
            t[o][3] = max(nums[l], 0);
            return;
        }
        int m = (l + r) / 2;
        build(nums, o * 2, l, m);
        build(nums, o * 2 + 1, m + 1, r);
        maintain(o);
    };

    // 把 nums[i] 改成 val
    void update(int o, int l, int r, int i, int val)
    {
        if (l == r)
        {
            t[o][3] = max(val, 0);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
        {
            update(o * 2, l, m, i, val);
        }
        else
        {
            update(o * 2 + 1, m + 1, r, i, val);
        }
        maintain(o);
    };

public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        t.resize(2 << (32 - __builtin_clz(n)));
        build(nums, 1, 0, n - 1);
        long long ans = 0;
        for (auto &q : queries)
        {
            update(1, 0, n - 1, q[0], q[1]);
            ans += t[1][3]; // 注意 f11 没有任何限制，也就是整个数组的打家劫舍
        }
        return ans % 1'000'000'007;
    }
};

// @lc code=end
