/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution
{
public:
    int countAsterisks(string s)
    {
        int n = s.size();
        vector<int> index;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
                index.push_back(i);
            if (s[i] == '*')
                count++;
        }
        if (index.empty())
            return count;
        for (int i = 0; i < index.size(); i += 2)
        {
            int begin = index[i], end = index[i + 1];
            for (int j = begin + 1; j < end; j++)
                if (s[j] == '*')
                    count--;
        }
        return count;
    }
};
// @lc code=end
