#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from, to;
vector<char> floor[100001];
bool visit[101] = {false, };
vector<pair<int, int>> ev_info(1, make_pair(0, 0));
queue<pair<vector<int>, int>> q;

void print_path(vector<int> &path)
{
	cout << path.size() << "\n";
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << "\n";
}

void push_q(vector<int> path, int ev_num, int current)
{
	int start, step;

	if (visit[ev_num])
		return ;
	visit[ev_num] = true;

	start = ev_info[ev_num].first;
	step = ev_info[ev_num].second;
	if (path.size() == 0)
		path.push_back(ev_num);
	else if (path[path.size() - 1] != ev_num)
		path.push_back(ev_num);
	while (start <= n)
	{
		if (start != current && floor[start].size() != 0)
			q.push(make_pair(path, start));
		start += step;
	}
}

void BFS()
{
	vector<int> init_path;
	pair<vector<int>, int> temp_pair;
	int current_floor;
	int ev_num;

	current_floor = from;
	for (int i = 0; i < floor[current_floor].size(); i++)
	{
		ev_num = floor[current_floor][i];
		push_q(init_path, ev_num, current_floor);
	}
	while (!q.empty())
	{
		temp_pair = q.front();
		q.pop();
		current_floor = temp_pair.second;
		if (current_floor == to)
		{
			print_path(temp_pair.first);
			return ;
		}
		for (int i = 0; i < floor[current_floor].size(); i++)
		{
			ev_num = floor[current_floor][i];
			push_q(temp_pair.first, ev_num, current_floor);
		}
	}
	cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int start;
	int step;
	for (int i = 1; i <= m; i++)
	{
		cin >> start >> step;
		ev_info.push_back(make_pair(start, step));
		while (start <= n)
		{
			//input ev number
			floor[start].push_back(i);
			start += step;
		}
	}
	cin >> from >> to;
	BFS();
	return 0;
}

// 16 4
// 2 4
// 3 3
// 5 7
// 6 2
// 9 8