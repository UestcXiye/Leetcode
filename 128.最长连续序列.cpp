/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start

// 哈希

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hash;
        // 把所有数字放到一个哈希表
        for (int &num : nums)
            hash.insert(num);
        int maxLen = 0;
        while (!hash.empty())
        {
            // 从哈希表中任意取一个值
            auto cur = *(hash.begin());
            hash.erase(cur);
            // 删除掉其之前之后的所有连续数字
            int next = cur + 1, prev = cur - 1;
            while (hash.count(next))
            {
                hash.erase(next);
                next++;
            }
            while (hash.count(prev))
            {
                hash.erase(prev);
                prev--;
            }
            // 更新目前的最长连续序列长度
            maxLen = max(maxLen, next - prev - 1);
        }
        return maxLen;
    }
};
// @lc code=end
