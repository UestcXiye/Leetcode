/*
 * @lc app=leetcode.cn id=3187 lang=cpp
 *
 * [3187] 数组中的峰值
 */

// @lc code=start
class Fenwick
{
    vector<int> f;

public:
    Fenwick(int n) : f(n) {}

    void update(int i, int val)
    {
        for (; i < f.size(); i += i & -i)
        {
            f[i] += val;
        }
    }

    int pre(int i)
    {
        int res = 0;
        for (; i > 0; i &= i - 1)
        {
            res += f[i];
        }
        return res;
    }

    int query(int l, int r)
    {
        if (r < l)
        {
            return 0;
        }
        return pre(r) - pre(l - 1);
    }
};

class Solution
{
public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        Fenwick f(n - 1);
        auto update = [&](int i, int val)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            {
                f.update(i, val);
            }
        };
        for (int i = 1; i < n - 1; i++)
        {
            update(i, 1);
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                ans.push_back(f.query(q[1] + 1, q[2] - 1));
                continue;
            }
            int i = q[1];
            for (int j = max(i - 1, 1); j <= min(i + 1, n - 2); ++j)
            {
                update(j, -1);
            }
            nums[i] = q[2];
            for (int j = max(i - 1, 1); j <= min(i + 1, n - 2); ++j)
            {
                update(j, 1);
            }
        }
        return ans;
    }
};
// @lc code=end
