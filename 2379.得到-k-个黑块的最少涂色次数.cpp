/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int left = 0, right = 0;
        int countWhiteBlock = 0;
        while (right < k)
        {
            countWhiteBlock += blocks[right] == 'W' ? 1 : 0;
            right++;
        }
        int ans = countWhiteBlock;
        while (right < n)
        {
            countWhiteBlock += blocks[right] == 'W' ? 1 : 0;
            countWhiteBlock -= blocks[left] == 'W' ? 1 : 0;
            ans = min(ans, countWhiteBlock);
            left++;
            right++;
        }
        return ans;
    }
};
// @lc code=end
