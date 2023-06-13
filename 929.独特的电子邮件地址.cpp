/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> emailSet;
        for (string &email : emails)
        {
            string localName;
            for (char &c : email)
            {
                if (c == '+' || c == '@')
                    break;
                if (c != '.')
                    localName += c;
            }
            string domainName = email.substr(email.find('@'));
            emailSet.insert(localName + domainName);
        }
        return emailSet.size();
    }
};
// @lc code=end
