/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = n - s1;
        for (int &sandwich : sandwiches)
        {
            if (sandwich == 0 && s0 > 0)
                s0--;
            else if (sandwich == 1 && s1 > 0)
                s1--;
            else
                break;
        }
        return s0 + s1;
    }
};
// @lc code=end
