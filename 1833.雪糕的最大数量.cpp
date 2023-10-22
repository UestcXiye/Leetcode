/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution
{
private:
#define MAX_ELEMENT 1e5
#define MAX_N 1e5 + 1
    // 计数排序
    void CountSort(vector<int> &vec)
    {
        vector<int> cnt(MAX_N, 0);
        for (int &v : vec)
            cnt[v]++;
        int index = 0;
        for (int i = 1; i <= MAX_ELEMENT; i++)
            for (int j = 0; j < cnt[i]; j++)
            {
                vec[index] = i;
                index++;
            }
    }

public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int ice_cream = 0;
        CountSort(costs);
        for (int &cost : costs)
        {
            if (coins >= cost)
            {
                coins -= cost;
                ice_cream++;
            }
            else
                break;
        }
        return ice_cream;
    }
};
// @lc code=end
