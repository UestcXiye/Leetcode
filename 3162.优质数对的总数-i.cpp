/*
 * @lc app=leetcode.cn id=3162 lang=cpp
 *
 * [3162] 优质数对的总数 I
 */

// @lc code=start
class Solution
{
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int count = 0;
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++)
                if (nums1[i] % (nums2[j] * k) == 0)
                    count++;
        return count;
    }
};
// @lc code=end
