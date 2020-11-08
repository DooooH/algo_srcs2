#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int from, to;
bool visit[10000] = {false, };
pair<char, int> parent[10000];
queue<pair<int, int>> q;

int oper_D(int &num)
{
	int temp = num;

	temp = (2 * temp) % 10000;
	return temp;
}

int oper_S(int &num)
{
	int temp = num;
	if (temp - 1 != 0)
		temp = temp - 1;
	else
		temp = 9999;
	return temp;
}

int oper_L(int &num)
{
	int d1, d2, d3, d4;
	int temp = num;

	d1 = temp / 1000;
	temp = temp % 1000;
	d2 = temp / 100;
	temp = temp % 100;
	d3 = temp / 10;
	temp = temp % 10;
	d4 = temp;

	temp = 0;
	temp += d2 * 1000;
	temp += d3 * 100;
	temp += d4 * 10;
	temp += d1;
	return temp;
}

int oper_R(int &num)
{
	int d1, d2, d3, d4;
	int temp = num;

	d1 = temp / 1000;
	temp = temp % 1000;
	d2 = temp / 100;
	temp = temp % 100;
	d3 = temp / 10;
	temp = temp % 10;
	d4 = temp;

	temp = 0;
	temp += d4 * 1000;
	temp += d1 * 100;
	temp += d2 * 10;
	temp += d3;
	return temp;
}

void push_elem(char c, int current, int temp, int count)
{
	if (visit[temp] == false)
	{
		q.push(make_pair(temp, count));
		parent[temp] = make_pair(c, current);
		visit[temp] = true;
	}
}

void print_answer()
{
	vector<char> answer;
	int iter;

	iter = to;
	while (iter != from)
	{
		answer.push_back(parent[iter].first);
		iter = parent[iter].second;
	}
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i];
	}
	cout << "\n";
}

void BFS()
{
	int temp;
	pair<int, int> current;

	q.push(make_pair(from, 1));
	visit[from] = true;
	while(!q.empty())
	{
		current = q.front();
		if (current.first == to)
		{
			print_answer();
			break ;
		}
		q.pop();
		temp = oper_D(current.first);
		push_elem('D', current.first, temp, current.second + 1);
		temp = oper_S(current.first);
		push_elem('S', current.first, temp, current.second + 1);
		temp = oper_L(current.first);
		push_elem('L', current.first, temp, current.second + 1);
		temp = oper_R(current.first);
		push_elem('R', current.first, temp, current.second + 1);
	}
}

void clear_queue(queue<pair<int, int>> &q)
{
    queue<pair<int, int>> empty;
    swap(q, empty);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		BFS();
		clear_queue(q);
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}

// 1
// 2345 3546 