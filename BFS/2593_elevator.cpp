#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from, to;
vector<short> floor[100001];
bool visit[101] = {false, };
short parent[101] = {0,};
short count_path[101] = {0,};
vector<pair<int, int>> ev_info(1, make_pair(0, 0));
queue<int> q;

void print_path()
{
	int ev = to;

	cout << count_path[to] << "\n"; 
	while (ev != 0)
	{
		cout << ev << "\n";
		ev = parent[ev];
	}
}

void push_q(int ev_num, int current, int count)
{
	int start, step;

	if (visit[ev_num])
		return ;
	visit[ev_num] = true;

	start = ev_info[ev_num].first;
	step = ev_info[ev_num].second;
	while (start <= n)
	{
		if (start != current && floor[start].size() != 0)
		{
			q.push(start);
			for (int i = 0; i < floor[start].size(); i++)
			{
				parent[floor[start][i]] = ev_num;
				count_path[floor[start][i]] = count;
			}
		}
		start += step;
	}
}

void BFS()
{
	vector<int> init_path;
	int current_floor;
	int ev_num;
	int q_size;
	int count = 0;

	current_floor = from;
	count++;
	for (int i = 0; i < floor[current_floor].size(); i++)
	{
		ev_num = floor[current_floor][i];
		push_q(ev_num, current_floor, count);
	}
	while (!q.empty())
	{
		q_size = q.size();
		for (int i = 0; i < q_size; i++)
		{
			current_floor = q.front();
			q.pop();
			if (current_floor == to)
			{
				print_path();
				return ;
			}
			count++;
			for (int i = 0; i < floor[current_floor].size(); i++)
			{
				ev_num = floor[current_floor][i];
				push_q(ev_num, current_floor, count);
			}
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