#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int from, to;
bool visit[10001] = {false, };
queue<pair<string, int>> q;

int oper_D(int num)
{
	return (num * 2) % 10000;
}

int oper_S(int num)
{
	if (num == 0)
		return 9999;
	else
		return num - 1;
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

void BFS()
{
	string path;
	int current_num;

	q.push(make_pair("", from));
	visit[from] = true;
	while (!q.empty())
	{
		path = q.front().first;
		current_num = q.front().second;
		q.pop();
		if (current_num == to)
			break;
		if (visit[oper_D(current_num)] == false)
		{
			q.push(make_pair(path + "D", oper_D(current_num)));
			visit[oper_D(current_num)] = true;
		}
		if (visit[oper_S(current_num)] == false)
		{
			q.push(make_pair(path + "S", oper_S(current_num)));
			visit[oper_S(current_num)] = true;
		}
		if (visit[oper_L(current_num)] == false)
		{
			q.push(make_pair(path + "L", oper_L(current_num)));
			visit[oper_L(current_num)] = true;
		}
		if (visit[oper_R(current_num)] == false)
		{
			q.push(make_pair(path + "R", oper_R(current_num)));
			visit[oper_R(current_num)] = true;
		}
	}
	cout << path << "\n";
}

void clear_queue()
{
	while (!q.empty())
		q.pop();
}

int main()
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(visit, false, sizeof(visit));
		cin >> from >> to;
		BFS();
		clear_queue();
	}

	return 0;
}