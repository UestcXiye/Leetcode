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
        long long ans = 0;
        for (int i = 0; i < gifts.size(); i++)
            ans += gifts[i];
        return ans;
    }
};
// @lc code=end
