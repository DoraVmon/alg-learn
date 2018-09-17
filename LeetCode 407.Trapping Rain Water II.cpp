#include <stdio.h>

#include <vector>

#include <queue>
struct Qitem{
	int x;
	int y;
	int h;
	Qitem(int _x, int _y, int _h) : 
		x(_x), y(_y), h(_h){
	}
};
struct cmp{
	bool operator()(const Qitem &a, const Qitem &b){
		return a.h > b.h;
	}
};

class Solution {
public:
    int trapRainWater(std::vector<std::vector<int> >& heightMap) {    	
		if(heightMap.size() < 3 || heightMap[0].size() < 3)
		{
			return 0;
		}

		int row = heightMap.size();
		int col = heightMap[0].size();
		std::vector<std::vector<int> > mark;
		for(int i = 0; i < row; i++)
		{
			mark.push_back(std::vector<int>());
			for(int j = 0; j < col; j++)
			{
				mark[i].push_back(0);
			}
		}

		std::priority_queue<Qitem, std::vector<Qitem>, cmp> Q;
		for(int i = 0; i < col; i++)
		{
			mark[0][i] = 1;
			Q.push(Qitem(0, i, heightMap[0][i]));
			mark[row-1][i] = 1;
			Q.push(Qitem(row-1, i, heightMap[row-1][i]));
		}
		for(int i = 1; i < row - 1; i++)
		{
			mark[i][0] = 1;
			Q.push(Qitem(i, 0, heightMap[i][0]));
			mark[i][col-1] = 1;
			Q.push(Qitem(i, col-1, heightMap[i][col-1]));
		}

		int ret = 0;
		while(!Q.empty())
		{
			int x = Q.top().x;
			int y = Q.top().y;
			int h = Q.top().h;
			Q.pop();
			static int dx[] = {0, -1, 0, 1};
			static int dy[] = {-1, 0, 1, 0};
			for(int i = 0; i < 4; i++)
			{
				int newx = x + dx[i];
				int newy = y + dy[i];
				if(newx < 0 || newy < 0 || newx >= row || newy >= col)
				{
					continue;
				}
				if(mark[newx][newy] == 0)
				{
					if(h > heightMap[newx][newy])
					{
						ret += h - heightMap[newx][newy];
						heightMap[newx][newy] = h;
					}
					mark[newx][newy] = 1;
					Q.push(Qitem(newx, newy, heightMap[newx][newy]));
				}
			}		
		}
		
		return ret;
    }
};

int main(){
	int test[][10] = {
		{1, 4, 3, 1, 3, 2},
		{3, 2, 1, 3, 2, 4},
		{2, 3, 3, 2, 3, 1}
	};
	std::vector<std::vector<int> > heightMap;
	for (int i = 0; i < 3; i++){
		heightMap.push_back(std::vector<int> ());
		for (int j = 0; j < 6; j++){
			heightMap[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.trapRainWater(heightMap));	
	return 0;
}
