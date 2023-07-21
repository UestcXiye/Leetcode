/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        const string morseCode[26] = {
            ".-", "-...", "-.-.", "-..", ".",
            "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---",
            ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--",
            "--.."};
        set<string> morseWords;
        for (string &word : words)
        {
            string morseWord;
            for (char &c : word)
                morseWord += morseCode[c - 'a'];
            morseWords.insert(morseWord);
        }
        return morseWords.size();
    }
};
// @lc code=end
