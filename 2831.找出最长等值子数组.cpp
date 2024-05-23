/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 *
 * [2831] 找出最长等值子数组
 */

// @lc code=start
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> posList;
        for (int i = 0; i < n; i++)
            posList[nums[i]].push_back(i);

        int ans = 0;
        for (auto &[_, pos] : posList)
        {
            int left = 0;
            for (int right = 0; right < pos.size(); right++)
            {
                // int subLen = pos[right] - pos[left] + 1;
                // int count = right - left + 1;
                // int needDelete = subLen - count;
                while ((pos[right] - pos[left] + 1) - (right - left + 1) > k)
                    left++;
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
