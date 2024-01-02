/*
 * @lc app=leetcode.cn id=2960 lang=cpp
 *
 * [2960] 统计已测试设备
 */

// @lc code=start
class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        if (batteryPercentages.empty())
            return 0;
        int count = 0;
        for (int i = 0; i < batteryPercentages.size(); i++)
        {
            if (batteryPercentages[i] > 0)
            {
                count++;
                for (int j = i + 1; j < batteryPercentages.size(); j++)
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
            }
        }
        return count;
    }
};
// @lc code=end
