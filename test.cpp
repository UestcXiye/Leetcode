#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main()
{
	string word1 = "bcca", word2 = "abc";
	
	vector<int> cnt(26, 0);
	for (char &c : word2)
		cnt[c - 'a']--;
	int shortage = 0;
	for (int i = 0; i < cnt.size(); i++)
		if (cnt[i] < 0)
			shortage++;

	int len1 = word1.size();
	long long ans = 0LL;
	for (int left = 0, right = 0; left < len1; left++)
	{
		while (right < len1 && shortage > 0)
		{
			cnt[word1[right]]++;
			if (cnt[word1[right]] >= 0)
				shortage--;
			right++;
		}

		if (shortage == 0)
			ans += len1 - right + 1;

		cnt[word1[left]]--;
		if (cnt[word1[left]] < 0)
			shortage++;
	}

	cout << ans << endl;

	system("pause");
	return 0;
}