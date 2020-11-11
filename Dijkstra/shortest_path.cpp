#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

using namespace std;

int v, e, start;
int from, to, cost;
vector<pair<int, int>> link[20001];
int dist[20001];
priority_queue<pair<int, int>> pq;

bool is_samekey(pair<int, int> a, int val){
	return a.first == val;
}

void init_array()
{
	for (int i = 1; i <= v; i++)
	{
		if (i == start)
		{
			dist[i] = 0;
			continue;
		}
		dist[i] = INF;
	}
}

void dijkstra()
{
	int current;
	int distance;
	int node;
	int node_cost;

	init_array();
	pq.push({0, start});
	while (!pq.empty())
	{
		current = pq.top().second;
		distance = -pq.top().first;
		pq.pop();
		if (dist[current] < distance) continue;
		for (int i = 0; i < link[current].size(); i++)
		{
			node = link[current][i].first;
			node_cost = link[current][i].second;
			if (dist[node] >= distance + node_cost){
				dist[node] = distance + node_cost;
				pq.push({-dist[node], node});
			}
		}
	}
}

int find_key()
{
	for (int i = 0; i < link[from].size(); i++)
	{
		if (link[from][i].first == to)
			return i;
	}
	return -1;
}

int main()
{
	int idx;

	cin >> v >> e;
	cin >> start;
	for (int i = 0; i < e; i++)
	{
		cin >> from >> to >> cost;
		if ((idx = find_key()) != -1)
			link[from][idx].second = min(cost, link[from][idx].second);
		else
			link[from].push_back({to, cost});
	}
	dijkstra();
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}