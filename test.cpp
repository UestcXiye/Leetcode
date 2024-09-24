#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

struct Node
{
	int val;
	Node *next;

	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node *n) : val(0), next(n) {}
};

int getLength(Node *head)
{
	int len = 0;
	Node *p = head;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

bool check(Node *head)
{
	vector<int> arr;
	Node *p = head;
	while (p)
	{
		arr.push_back(p->val);
		p = p->next;
	}
	int i = 0, j = arr.size() - 1;
	for (; i <= j; i++, j--)
		if (arr[i] != arr[j])
			return false;
	return true;
}

int main()
{
	Node *head = new Node();
	Node *p = head;
	for (int i = 1; i < 6; i++)
	{
		Node *n = new Node(i);
		p->next = n;
		p = p->next;
	}
	for (int i = 5; i >= 0; i--)
	{
		Node *n = new Node(i);
		p->next = n;
		p = p->next;
	}

	cout << getLength(head) << endl;
	if (check(head))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	system("pause");
	return 0;
}