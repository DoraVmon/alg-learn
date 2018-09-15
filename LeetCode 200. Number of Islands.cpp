#include <stdio.h>

#include <vector>
#include <queue>

class Solution
{
  public:
	int numIslands(std::vector<std::vector<char> > &grid)
	{
		std::vector<std::vector<int> > mark;
		for (int i = 0; i < grid.size(); i++)
		{
			mark.push_back(std::vector<int>());
			for (int j = 0; j < grid[i].size(); j++)
			{
				mark[i].push_back(0);
			}
		}
		int ret = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1' && mark[i][j] == 0)
				{
					BFS(grid, mark, i, j);
					++ret;
				}
			}
		}
		return ret;
	}

  private:
	void BFS(
		std::vector<std::vector<char> > &grid,
		std::vector<std::vector<int> > &mark,
		int x, int y)
	{
		std::queue<std::pair<int, int> > Q;
		Q.push(std::make_pair(x, y));
		mark[x][y] = 1;
		static int dx[] = {-1, +1, 0, 0};
		static int dy[] = {0, 0, -1, +1};
		while(!Q.empty())
		{
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();
			for(int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (new_x < 0 || new_x >= mark.size() || new_y < 0 || new_y >= mark[new_x].size())
				{
					continue;
				}
				if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
				{
					Q.push(std::make_pair(new_x, new_y));
					mark[new_x][new_y] = 1;
				}
			}
		}
	}
	void DFS(
		std::vector<std::vector<char> > &grid,
		std::vector<std::vector<int> > &mark,
		int x, int y)
	{
		mark[x][y] = 1;
		static int dx[] = {-1, +1, 0, 0};
		static int dy[] = {0, 0, -1, +1};
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (new_x < 0 || new_x >= mark.size() || new_y < 0 || new_y >= mark[new_x].size())
			{
				continue;
			}
			if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
			{
				DFS(grid, mark, new_x, new_y);
			}
		}
	}
};

int main(){
	std::vector<std::vector<char> > grid;
	char str[10][10] = {"11100", "11000", "00100", "00011"};
	for (int i = 0; i < 4; i++){
		grid.push_back(std::vector<char>());
		for (int j = 0; j < 5; j++){
			grid[i].push_back(str[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.numIslands(grid));
	return 0;
}
