/*
 * @lc app=leetcode.cn id=2678 lang=cpp
 *
 * [2678] 老人的数目
 */

// @lc code=start
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int count = 0;
        for (string &detail : details)
        {
            int age = stoi(detail.substr(11, 2));
            if (age > 60)
                count++;
        }
        return count;
        }
};
// @lc code=end
