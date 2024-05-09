/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 *
 * [2105] 给植物浇水 II
 */

// @lc code=start
class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int i = 0, j = n - 1;
        int a = capacityA, b = capacityB;
        int count = 0;
        while (i < j)
        {
            if (a < plants[i])
            {
                a = capacityA;
                count++;
            }
            a -= plants[i];
            i++;

            if (b < plants[j])
            {
                b = capacityB;
                count++;
            }
            b -= plants[j];
            j--;
        }
        if (i == j && max(a, b) < plants[i])
            count++;
        return count;
    }
};
// @lc code=end
