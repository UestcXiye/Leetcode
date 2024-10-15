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

        int ans = INT_MIN;
        for (auto &[_, pos] : posList)
        {
            int left = 0;
            for (int right = 0; right < pos.size(); right++)
            {
                // subLen 是子数组的长度
                int subLen = pos[right] - pos[left] + 1;
                // count 是等值元素的个数
                int count = right - left + 1;
                while (subLen - count > k)
                {
                    left++;
                    subLen = pos[right] - pos[left] + 1;
                    count = right - left + 1;
                }
                ans = max(ans, count);
            }
        }

        return ans;
    }
};
// @lc code=end
