#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string word = "abbc";
    vector<int> alphaCount(26, 0);
    for (int i = 0; i < word.size(); i++)
        alphaCount[word[i] - 'a']++;
    sort(alphaCount.begin(), alphaCount.end());
    for (int i = 0; i < 26; i++)
        if (alphaCount[i] == 0)
            alphaCount.erase(i);
    for (int i = 0; i < 26; i++)
        cout << alphaCount[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}
