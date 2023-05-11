/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> answer(m);
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            int count = 0;
            int index = 0;
            while (index < n && sum <= queries[i])
            {
                sum += nums[index];
                index++;
                if (sum <= queries[i])
                    count++;
            }
            answer[i] = count;
        }
        return answer;
    }
};
// @lc code=end
