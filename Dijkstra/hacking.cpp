#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int test, num, depend, start;
int from, to, cost;
vector<pair<int, int>> link[10001];
int dist[10001];
priority_queue<pair<int, int>> pq;

void dijkstra(int start)
{
	
}

int main()
{
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> num >> depend >> start;
		for (int j = 0; j < depend; j++)
		{
			cin >> to >> from >> cost;
			link[from].push_back(make_pair(to, cost));
		}
		dijkstra(start);
	}
	return 0;
}