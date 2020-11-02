#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer_cnt = 0;

// set subsum = 0, idx = 0
void dfs(vector<int> &numbers, int &target, vector<int> &subsums, int subsum, int idx)
{
	if (idx == numbers.size())
		return ;
	if (abs(target - subsum) > subsums[idx])
		return ;
	for (int i = 0; i < 2; i++)
	{
		int tempsum = subsum;
		int add = 1;
		if (i == 1)
			add = -1;
		tempsum += add * numbers[idx];
		if ((idx == numbers.size() - 1) && tempsum == target)
			answer_cnt++;
		dfs(numbers, target, subsums, tempsum, idx + 1);
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int tempsum = 0;
	vector<int> subsums(numbers.size(), 0);
	for (int i = numbers.size() - 1; i >= 0; i--)
	{
		tempsum += numbers[i];
		subsums[i] = tempsum;
	}
	dfs(numbers, target, subsums, 0, 0);
	answer = answer_cnt;
	return answer;
}

#include <iostream>
int main()
{
	vector<int> numbers = {1, 1, 1, 1, 1};
	std::cout << solution(numbers, 3) << "\n";
	return 0;
}