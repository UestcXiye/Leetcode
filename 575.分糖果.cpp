/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_map<int, int> hash;
        for (int &candy : candyType)
            hash[candy]++;
        return min(candyType.size() / 2, hash.size());
    }
};
// @lc code=end
