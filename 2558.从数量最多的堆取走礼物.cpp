/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        for (int i = 0; i < k; i++)
        {
            sort(gifts.begin(), gifts.end());
            gifts[gifts.size() - 1] = sqrt(gifts[gifts.size() - 1]);
        }
        return (long long)accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
// @lc code=end
