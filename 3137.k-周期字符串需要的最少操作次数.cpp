/*
 * @lc app=leetcode.cn id=3137 lang=cpp
 *
 * [3137] K 周期字符串需要的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        int n = word.length();
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i += k)
        {
            string temp = word.substr(i, k);
            freq[temp]++;
        }
        int maxFreq = 1, total = n / k;
        for (auto &[s, cnt] : freq)
        {
            if (cnt > maxFreq)
                maxFreq = cnt;
        }
        return total - maxFreq;
    }
};
// @lc code=end
