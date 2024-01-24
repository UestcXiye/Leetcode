/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start

// 差分数组

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        // 构造差分数组
        vector<int> diff(n + 1, 0);
        for (vector<int> &booking : bookings)
        {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            diff[first - 1] += seats;
            diff[last] -= seats;
        }

        int sum = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            sum += diff[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
// @lc code=end
