/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 *
 * [3040] 相同分数的最大操作数目 II
 */

// @lc code=start

// 区间 DP + 记忆化搜索

class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        int n = nums.size();
        int memo[n][n];

        auto helper = [&](int i, int j, int target) -> int
        {
            memset(memo, -1, sizeof(memo));
            function<int(int, int)> dfs = [&](int i, int j) -> int
            {
                if (i >= j)
                    return 0;

                int &res = memo[i][j]; // 注意这里是引用
                if (res != -1)
                    return res;

                res = 0;

                if (nums[i] + nums[i + 1] == target)
                    res = max(res, dfs(i + 2, j) + 1);
                if (nums[j - 1] + nums[j] == target)
                    res = max(res, dfs(i, j - 2) + 1);
                if (nums[i] + nums[j] == target)
                    res = max(res, dfs(i + 1, j - 1) + 1);
                return res;
            };
            return dfs(i, j);
        };

        // 最前面两个
        int res1 = helper(2, n - 1, nums[0] + nums[1]);
        // 最后两个
        int res2 = helper(0, n - 3, nums[n - 2] + nums[n - 1]);
        // 第一个和最后一个
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1]);

        int ans = max({res1, res2, res3}) + 1; // 加上第一次操作
        return ans;
    }
};
// @lc code=end
