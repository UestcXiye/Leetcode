/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        // 如果 endWord 不在 dict 里，跳过
        if (dict.count(endWord) == 0)
            return ans;
        // 特殊用例处理
        dict.erase(beginWord);
        // 第1步：广度优先搜索建图
        // steps 记录扩展出的单词是在第几次扩展的时候得到的
        // key：单词，value：在广度优先搜索的第几层
        unordered_map<string, int> steps = {{beginWord, 0}};
        // from 记录了单词是从哪些单词扩展而来
        // key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
        unordered_map<string, set<string>> from = {{beginWord, {}}};
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{{beginWord}};
        int wordLen = beginWord.length();
        while (!q.empty())
        {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                // 将每一位替换成 26 个小写英文字母
                for (int j = 0; j < wordLen; j++)
                {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        nextWord[j] = c;
                        if (steps[nextWord] == step)
                            from[nextWord].insert(currWord);
                        if (dict.find(nextWord) == dict.end())
                            continue;
                        // 如果从一个单词扩展出来的单词以前遍历过，距离一定更远，为了避免搜索到已经遍历到且距离更远的单词，需要将它从 dict 中删除
                        dict.erase(nextWord);
                        // 这一层扩展出的单词进入队列
                        q.push(nextWord);
                        // 记录 nextWord 从 currWord 而来
                        from[nextWord].insert(currWord);
                        // 记录 nextWord 的 step
                        steps[nextWord] = step;
                        if (nextWord == endWord)
                            found = true;
                    }
                    nextWord[j] = origin;
                }
            }
            if (found)
                break;
        }
        // 第 2 步：回溯找到所有解，从 endWord 恢复到 beginWord ，所以每次尝试操作 path 列表的头部
        if (found)
        {
            vector<string> path = {endWord};
            backtrack(ans, endWord, from, path);
        }
        return ans;
    }

    void backtrack(vector<vector<string>> &ans, const string &node, unordered_map<string, set<string>> &from, vector<string> &path)
    {
        if (from[node].empty())
        {
            ans.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string &parent : from[node])
        {
            path.push_back(parent);
            backtrack(ans, parent, from, path);
            path.pop_back();
        }
    }
};
// @lc code=end
