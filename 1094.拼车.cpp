/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> diff(1001, 0);
        for (vector<int> &trip : trips)
        {
            int numPassengers = trip[0], from = trip[1], to = trip[2];
            diff[from] += numPassengers;
            diff[to] -= numPassengers;
        }
        int passengers = 0;
        for (int &d : diff)
        {
            passengers += d;
            if (passengers > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end
