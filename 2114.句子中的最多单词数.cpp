/*
 * @lc app=leetcode.cn id=2114 lang=cpp
 *
 * [2114] 句子中的最多单词数
 */

// @lc code=start
class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int maxCount = 0;
        for (string sentence : sentences)
        {
            int count = 0;
            for (char c : sentence)
                if (c == ' ')
                    count++;
            maxCount = max(maxCount, count);
        }
        return maxCount + 1;
    }
};
// @lc code=end
