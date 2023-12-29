/*
 * @lc app=leetcode.cn id=2948 lang=cpp
 *
 * [2948] 交换得到字典序最小的数组
 */

// @lc code=start
class Solution
{

public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        // 特判
        if (nums.empty())
            return {};
        if (limit <= 0)
            return nums;

        int n = nums.size();
        vector<int> index(n, 0);
        iota(index.begin(), index.end(), 0);
        // for (int i = 0; i < n; i++)
        //     index[i] = i;
        sort(index.begin(), index.end(), [&](int i, int j)
             { return nums[i] < nums[j]; });

        vector<int> ans(n, 0);
        // 分组循环
        int i = 0;
        // 外层循环：准备工作 + 更新答案
        while (i < n)
        {
            int start = i;
            i++;
            // 找出分组
            while (i < n && nums[index[i]] - nums[index[i - 1]] <= limit)
                i++;
            // [start, i) 属于一个分组
            // 提取出 nums[start, i) 中的下标
            vector<int> subIndex(index.begin() + start, index.begin() + i);
            sort(subIndex.begin(), subIndex.end());
            // 插入到答案数组
            for (int j = 0; j < subIndex.size(); j++)
                ans[subIndex[j]] = nums[index[start + j]];
        }
        return ans;
    }
};
// @lc code=end
