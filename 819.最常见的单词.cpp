/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
// class Solution
// {
// public:
//     string mostCommonWord(string paragraph, vector<string> &banned)
//     {
//         for (char &c : paragraph)
//             c = tolower(c);
//         unordered_map<string, int> freq;
//         istringstream iss(paragraph);
//         string s;
//         while (iss >> s)
//         {
//             string word;
//             for (char &c : s)
//                 if (isalpha(c))
//                     word += tolower(c);
//             freq[word]++;
//         }
//         unordered_set<string> bannedSet(banned.begin(), banned.end());
//         string ans;
//         int maxCount = 0;
//         for (auto &[word, count] : freq)
//         {
//             if (!bannedSet.count(word))
//             {
//                 if (count > maxCount)
//                 {
//                     maxCount = count;
//                     ans = word;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        int maxFrequency = 0;
        unordered_map<string, int> freq;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i++)
        {
            if (i < length && isalpha(paragraph[i]))
            {
                word.push_back(tolower(paragraph[i]));
            }
            else if (word.size() > 0)
            {
                if (!bannedSet.count(word))
                {
                    freq[word]++;
                    maxFrequency = max(maxFrequency, freq[word]);
                }
                word = "";
            }
        }
        string mostCommon = "";
        for (auto &[word, frequency] : freq)
        {
            if (frequency == maxFrequency)
            {
                mostCommon = word;
                break;
            }
        }
        return mostCommon;
    }
};
// @lc code=end
