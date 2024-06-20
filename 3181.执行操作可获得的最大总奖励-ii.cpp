/*
 * @lc app=leetcode.cn id=3181 lang=cpp
 *
 * [3181] 执行操作可获得的最大总奖励 II
 */

// @lc code=start
class Solution
{
public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        ranges::sort(rewardValues);
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        bitset<100000> f{1};
        for (int v : rewardValues)
        {
            int shift = f.size() - v;
            // 左移 shift 再右移 shift，把所有 >= v 的比特位置 0
            // f |= f << shift >> shift << v;
            f |= f << shift >> (shift - v); // 简化上式
        }
        for (int i = rewardValues.back() * 2 - 1;; i--)
            if (f.test(i))
                return i;
    }
};

// @lc code=end
