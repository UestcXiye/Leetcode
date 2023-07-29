/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        vector<int> licensePlateFreq(26, 0);
        for (char &c : licensePlate)
            if (isalpha(c))
                licensePlateFreq[tolower(c) - 'a']++;
        string ans;
        int minLength = __INT_MAX__;
        for (string &word : words)
        {
            vector<int> wordFreq(26, 0);
            for (char &c : word)
                wordFreq[c - 'a']++;
            bool judge = true;
            for (int i = 0; i < 26; i++)
                if (licensePlateFreq[i] > wordFreq[i])
                {
                    judge = false;
                    break;
                }
            if (judge == true)
            {
                if (word.size() < minLength)
                {
                    ans = word;
                    minLength = word.size();
                }
            }
        }
        return ans;
    }
};
// @lc code=end
