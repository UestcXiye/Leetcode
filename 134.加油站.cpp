/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int begin = 0;
        while (begin < n)
        {
            int sumOfGas = 0, sumOfCost = 0;
            int count = 0;
            while (count < n)
            {
                int index = (begin + count) % n;
                sumOfGas += gas[index], sumOfCost += cost[index];
                if (sumOfGas < sumOfCost)
                    break;
                count++;
            }
            if (count == n)
                return begin;
            else
            {
                // 从第一个无法到达的加油站开始继续检查
                begin += count + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
