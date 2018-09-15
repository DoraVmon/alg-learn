#include <stdio.h>
#include <queue>

#define MAXN 300

struct location{
	int x;
	int y;
	int step;
	location(int _x, int _y, int _step): x(_x), y(_y), step(_step) {}
};


int BFS_move(int beginx, int beginy, int endx, int endy, int n)
{
	int mark[MAXN][MAXN] = {0};
	std::queue<location> Q;
	Q.push(location(beginx, beginy, 0));
	mark[beginx][beginy] = 1;
	static int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	static int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	while(!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int step = Q.front().step;
		if(x == endx && y == endy)
		{
			return step;
		}
		Q.pop();
		for(int i = 0; i < 8; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
			{
				continue;
			}
			if(mark[new_x][new_y] == 0)
			{
				mark[new_x][new_y] = 1;
				Q.push(location(new_x, new_y, step+1));
			}
		}
	}
	return -1;
}

int main(){
	int t;
	int n;
	int beginx;
	int beginy;
	int endx;
	int endy;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &n, &beginx, &beginy, &endx, &endy);
		printf("%d\n", BFS_move(beginx, beginy, endx, endy, n));
	}
	return 0;
}

