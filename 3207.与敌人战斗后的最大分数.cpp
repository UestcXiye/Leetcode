/*
 * @lc app=leetcode.cn id=3207 lang=cpp
 *
 * [3207] 与敌人战斗后的最大分数
 */

// @lc code=start
class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {
        int minEnergy = *min_element(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < minEnergy)
            return 0;
        long long sum = accumulate(enemyEnergies.begin(), enemyEnergies.end(), 0LL);
        return (currentEnergy + sum - minEnergy) / minEnergy;
    }
};

// @lc code=end
