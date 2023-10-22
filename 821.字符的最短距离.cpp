/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size(), leftDistance = __INT_MAX__, rightDistance = __INT_MAX__;
        vector<int> shortestDistance(n, 0);
        for (int i = 0; i < n; i++)
        {
            int leftDistance = __INT_MAX__;
            string leftSubStr = s.substr(0, i + 1);
            for (int j = leftSubStr.size() - 1; j >= 0; j--)
                if (leftSubStr[j] == c)
                {
                    leftDistance = leftSubStr.size() - j - 1;
                    break;
                }
            int rightDistance = __INT_MAX__;
            string rightSubStr = s.substr(i, n - i);
            for (int j = 0; j < rightSubStr.size(); j++)
                if (rightSubStr[j] == c)
                {
                    rightDistance = j;
                    break;
                }
            shortestDistance[i] = min(leftDistance, rightDistance);
        }
        return shortestDistance;
    }
};
// @lc code=end
