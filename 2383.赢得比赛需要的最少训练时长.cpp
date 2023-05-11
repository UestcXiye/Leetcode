/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int neededEnergy = 0;
        int totalEnergy = 0;
        for (int e : energy)
            totalEnergy += e;
        if (initialEnergy <= totalEnergy)
            neededEnergy = totalEnergy - initialEnergy + 1;

        int currentExperience = initialExperience;
        int neededExperience = 0;
        for (int e : experience)
        {
            if (currentExperience <= e)
            {
                int diff = e - currentExperience + 1;
                currentExperience += diff;
                neededExperience += diff;
                currentExperience += e;
            }
            else
                currentExperience += e;
        }
        return neededEnergy + neededExperience;
    }
};
// @lc code=end
