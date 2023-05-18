/*
 * @lc app=leetcode.cn id=2037 lang=cpp
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

// @lc code=start
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int count = 0;
        for (int i = 0; i < n; i++)
            count += abs(seats[i] - students[i]);
        return count;
    }
};
// @lc code=end
