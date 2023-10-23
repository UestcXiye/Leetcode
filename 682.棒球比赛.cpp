/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> grades;
        for (string &op : operations)
        {
            if (op == "C")
                grades.pop_back();
            else if (op == "D")
            {
                int grade = grades.back();
                grades.push_back(2 * grade);
            }
            else if (op == "+")
            {
                int grade = grades[grades.size() - 2] + grades[grades.size() - 1];
                grades.push_back(grade);
            }
            else
                grades.push_back(stoi(op));
        }
        return accumulate(grades.begin(), grades.end(), 0);
    }
};
// @lc code=end
