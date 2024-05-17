/*
 * @lc app=leetcode.cn id=3149 lang=cpp
 *
 * [3149] 找出分数最低的排列
 */

// @lc code=start
class Solution
{
public:
    vector<int> findPermutation(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> memo(1 << n, vector<int>(n, -1)); // -1 表示没有计算过
        // s 表示前面已选的下标集合，j 表示上一个位置的下标
        function<int(int, int)> dfs = [&](int s, int j) -> int
        {
            if (s == (1 << n) - 1)
            { // 所有位置都填完了，最后一个位置是下标 j
                return abs(j - nums[0]);
            }
            int &res = memo[s][j]; // 注意这里是引用
            if (res != -1)
            { // 之前计算过
                return res;
            }
            res = INT_MAX;
            // 枚举当前位置填下标 k
            for (int k = 1; k < n; k++)
            {
                if ((s >> k & 1) == 0)
                { // k 之前没填过
                    res = min(res, dfs(s | 1 << k, k) + abs(j - nums[k]));
                }
            }
            return res;
        };

        vector<int> ans;
        // 找到最佳路径
        function<void(int, int)> make_ans = [&](int s, int j) -> void
        {
            ans.push_back(j);
            if (s == (1 << n) - 1)
                return;
            int final_res = dfs(s, j);
            for (int k = 1; k < n; k++)
            {
                if ((s >> k & 1) == 1)
                { // k 之前填过
                    continue;
                }
                if (dfs(s | 1 << k, k) + abs(j - nums[k]) == final_res)
                {
                    make_ans(s | 1 << k, k);
                    break;
                }
            }
        };
        make_ans(1, 0);
        return ans;
    }
};
// @lc code=end
