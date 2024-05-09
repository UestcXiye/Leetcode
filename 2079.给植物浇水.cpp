/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start
class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int n = plants.size();
        int sum = 0;
        int water = capacity;
        for (int i = 0; i < n; i++)
        {
            int plant = plants[i];
            // 没有足够的水完全浇灌下一株植物
            if (water < plant)
            {
                // 回到河边取水，来回的步数为 2 * i
                sum += 2 * i;
                // 重新装满水罐
                water = capacity;
            }
            // 浇水
            water -= plant;
            // 步数 +1
            sum++;
        }
        return sum;
    }
};
// @lc code=end
