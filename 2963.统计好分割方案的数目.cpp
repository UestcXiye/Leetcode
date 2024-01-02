/*
 * @lc app=leetcode.cn id=2963 lang=cpp
 *
 * [2963] 统计好分割方案的数目
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    int numberOfGoodPartitions(vector<int> &nums)
    {
        // <num, pair<firstIndex, lastIndex>>
        unordered_map<int, pair<int, int>> positions;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            auto it = positions.find(num);
            if (it != positions.end())
                it->second.second = i;
            else
                positions[num] = pair<int, int>(i, i);
        }
        // 合并区间
        vector<vector<int>> intervals;
        for (auto &[_, p] : positions)
            intervals.push_back({p.first, p.second});
        // 按区间左端点排序
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> merge;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if (merge.empty() || merge.back()[1] < left)
                merge.push_back(intervals[i]);
            else
                merge.back()[1] = max(merge.back()[1], right);
        }
        return (int)myPow(2, merge.size() - 1, 1e9 + 7);
    }
    // 辅函数 - 快速幂
    long long myPow(long long x, int n, const int mod)
    {
        long long res = 1;
        while (n)
        {
            if (n & 01)
                res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end
