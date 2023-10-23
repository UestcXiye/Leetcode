/*
 * @lc app=leetcode.cn id=1854 lang=cpp
 *
 * [1854] 人口最多的年份
 */

// @lc code=start
class Solution
{
private:
    const int offset = 1950;

public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> delta(101, 0);
        for (vector<int> &log : logs)
        {
            delta[log[0] - offset]++;
            delta[log[1] - offset]--;
        }
        int max_population = INT_MIN, year = 0, cur_population = 0;
        for (int i = 0; i < delta.size(); i++)
        {
            cur_population += delta[i];
            if (cur_population > max_population)
            {
                max_population = cur_population;
                year = i + offset;
            }
        }
        return year;
    }
};
// @lc code=end
