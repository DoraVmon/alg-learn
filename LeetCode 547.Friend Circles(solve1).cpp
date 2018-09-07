#include <stdio.h>

#include <vector>


class Solution
{
  public:
	int findCircleNum(std::vector<std::vector<int>> &M)
	{
		std::vector<int> visit(M.size(), 0);
		int ret = 0;
		for (int i = 0; i < M.size(); i++)
		{
			if (visit[i] == 0)
			{
				DFS_search(i, M, visit);
				ret++;
			}
		}
		return ret;
	}

  private:
	void DFS_search(int id,
					std::vector<std::vector<int>> &graph,
					std::vector<int> &visit)
	{
		visit[id] = 1;
		for (int i = 0; i < graph.size(); i++)
		{
			if (visit[i] == 0 && graph[id][i] == 1)
			{
				DFS_search(i, graph, visit);
			}
		}
	}
};

int main(){
	int test[][3] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	std::vector<std::vector<int> > M(3, std::vector<int>(3, 0));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			M[i][j] = test[i][j];
		}
	}
	Solution solve;
	printf("%d\n", solve.findCircleNum(M));
	return 0;
}
