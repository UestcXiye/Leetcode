#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

string wordBits(string word)
{
    string bits(26, '0');
    for (int i = 0; i < word.size(); i++)
        bits[word[i] - 'a'] = 1;
    return bits;
}

int similarPairs(vector<string> &words)
{
    int ans = 0;
    int n = words.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (wordBits(words[i]) == wordBits(words[j]))
                ans++;
    return ans;
}

int main()
{
    vector<string> words = {"aba", "aabb", "abcd", "bac", "aabc"};
    cout << similarPairs(words) << endl;

    system("pause");
    return 0;
}
