/*
 * @lc app=leetcode.cn id=3306 lang=cpp
 *
 * [3306] 元音辅音字符串计数 II
 */

// @lc code=start
class Solution
{
private:
    const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

public:
    long long countOfSubstrings(string word, int k)
    {
        return f(word, k) - f(word, k + 1);
    }
    // 辅函数
    long long f(string &word, int k)
    {
        long long ans = 0;
        // 这里用哈希表实现，替换成数组会更快
        unordered_map<char, int> cnt1; // 每种元音的个数
        int cnt2 = 0;                  // 辅音个数
        int left = 0;
        for (char &c : word)
        {
            if (vowels.count(c))
                cnt1[c]++;
            else
                cnt2++;
            while (cnt1.size() == 5 && cnt2 >= k)
            {
                char out = word[left];
                if (vowels.count(out))
                {
                    if (--cnt1[out] == 0)
                        cnt1.erase(out);
                }
                else
                    cnt2--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end
