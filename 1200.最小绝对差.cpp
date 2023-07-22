/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = __INT_MAX__;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = arr[i + 1] - arr[i];
            minDiff = min(diff, minDiff);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = arr[i + 1] - arr[i];
            if (diff == minDiff)
                ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};
// @lc code=end
