#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int countPrimeFactors(int x)
{
	unordered_set<int> primeFactors;
	for (int i = 2; i <= sqrt(x); i++)
	{
		while (x % i == 0)
		{
			primeFactors.insert(i);
			x /= i;
		}
	}
	if (x > 1)
		primeFactors.insert(x);
	return primeFactors.size();
}

// void dfs(int node, int parent, const vector<int> &primeFactorCounts, const vector<vector<int>> &g,
// 		 unordered_set<int> &operations, unordered_map<int, vector<int>> &edgesToColor)
// {
// 	for (int neighbor : g[node])
// 	{
// 		if (neighbor == parent)
// 			continue;
// 		dfs(neighbor, node, primeFactorCounts, g, operations, edgesToColor);

// 		if (primeFactorCounts[node] == primeFactorCounts[neighbor])
// 		{
// 			edgesToColor[node].push_back(neighbor);
// 			edgesToColor[neighbor].push_back(node);
// 		}
// 	}

// 	if (edgesToColor[node].size() > 0)
// 		operations.insert(node);
// }

int main()
{
	int n;
	cin >> n;

	vector<int> weights(n + 1);
	vector<int> primeFactorCounts(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> weights[i];
		primeFactorCounts[i] = countPrimeFactors(weights[i]);
	}

	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	unordered_set<int> operations;
	unordered_map<int, vector<int>> edgesToColor;

	function<void(int, int)> dfs = [&](int node, int parent)
	{
		for (int neighbor : g[node])
		{
			if (neighbor == parent)
				continue;
			dfs(neighbor, node);

			if (primeFactorCounts[node] == primeFactorCounts[neighbor])
			{
				edgesToColor[node].push_back(neighbor);
				edgesToColor[neighbor].push_back(node);
			}
		}

		if (edgesToColor[node].size() > 0)
			operations.insert(node);
	};

	dfs(1, -1);

	cout << operations.size() << endl;
	if (!operations.empty())
	{
		vector<int> res(operations.begin(), operations.end());
		sort(res.begin(), res.end());
		for (int &p : res)
			cout << p << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}