/*
 * @lc app=leetcode.cn id=2926 lang=cpp
 *
 * [2926] 平衡子序列的最大和
 */

// @lc code=start
// 树状数组模板（维护前缀最大值）
class BIT
{
    vector<long long> tree;

public:
    BIT(int n) : tree(n, LLONG_MIN) {}

    void update(int i, long long val)
    {
        while (i < tree.size())
        {
            tree[i] = max(tree[i], val);
            i += i & -i;
        }
    }

    long long pre_max(int i)
    {
        long long res = LLONG_MIN;
        while (i > 0)
        {
            res = max(res, tree[i]);
            i &= i - 1;
        }
        return res;
    }
};

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();
        // 离散化 nums[i]-i
        auto b = nums;
        for (int i = 0; i < n; i++)
        {
            b[i] -= i;
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end()); // 去重

        BIT t = BIT(b.size() + 1);
        for (int i = 0; i < n; i++)
        {
            // j 为 nums[i]-i 离散化后的值（从 1 开始）
            int j = lower_bound(b.begin(), b.end(), nums[i] - i) - b.begin() + 1;
            long long f = max(t.pre_max(j), 0LL) + nums[i];
            t.update(j, f);
        }
        return t.pre_max(b.size());
    }
};

// @lc code=end
