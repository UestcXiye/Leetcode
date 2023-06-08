/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        if (stones.size() == 1)
            return stones[0];
        while (stones.size() > 1)
        {
            int n = stones.size();
            vector<int> temp;
            sort(stones.begin(), stones.end());
            for (int i = 0; i < n - 2; i++)
                temp.push_back(stones[i]);
            if (stones[n - 2] != stones[n - 1])
                temp.push_back(stones[n - 1] - stones[n - 2]);
            stones = temp;
        }
        if (stones.size() == 1)
            return stones[0];
        return 0;
    }
};
// @lc code=end
