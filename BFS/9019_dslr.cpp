#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int from, to;
queue<pair<string, int>> q;
int visit[10000] = {0, };

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

void push_elem(char c, int temp, pair<string, int> front_elem)
{
	string str_temp;

	str_temp = front_elem.first;
	if (visit[temp] != -1 && (visit[temp] == 0 || visit[temp] >= (str_temp.length() + 1)))
	{
		str_temp.push_back(c);
		q.push(make_pair(str_temp, temp));
		visit[temp] = str_temp.length();
	}
}

string BFS()
{
	int temp;
	string str_temp = "";
	pair<string, int> front_elem;

	q.push(make_pair(str_temp, from));
	visit[from] = -1;
	while(!q.empty())
	{
		front_elem = q.front();
		if (front_elem.second == to)
			return front_elem.first;
		q.pop();
		temp = oper_D(front_elem.second);
		push_elem('D', temp, front_elem);
		temp = oper_S(front_elem.second);
		push_elem('S', temp, front_elem);
		temp = oper_L(front_elem.second);
		push_elem('L', temp, front_elem);
		temp = oper_R(front_elem.second);
		push_elem('R', temp, front_elem);
	}
	return "";
}

void clear_queue(queue<pair<string, int>> &q)
{
    queue<pair<string, int>> empty;
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
		cout << BFS() << "\n";
		clear_queue(q);
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}

// 1
// 2345 3546 