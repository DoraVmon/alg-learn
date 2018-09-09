#include <stdio.h>

#include <vector>

class DisjointSet{
public:
	DisjointSet(int n){
		for(int i = 0; i < n; i++) {
			_id.push_back(i);
			_size.push_back(i);
		}
		_count = n;
	}
	int find(int p){
		while(p != _id[p]) {
			_id[p] = _id[_id[p]];
			p = _id[p];
		}
		return _id[p];
	}
	void unin(int p, int q){
		int id_p = find(p);
		int id_q = find(q);
		if(id_p == id_q) {
			return;
		}
		// _id[id_p] = _id[id_q];
		if(_size[id_p] < _size[id_q]) {
			_id[id_p] = id_q;
			_size[id_q] += _size[id_p];
		}
		else {
			_id[id_q] = id_p;
			_size[id_p] += _size[id_q];
		}
		_count--;
	}
	int count(){
		return _count;
	}
private:
	std::vector<int> _id;
	std::vector<int> _size;
	int _count;
};

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int> >& M) {
		DisjointSet disjntSet(M.size());
		for(int i = 0; i < M.size(); i++) {
			for(int j = i + 1; j < M.size(); j++) {
				if(M[i][j] == 1) {
					disjntSet.unin(i, j);
				}
			}
		}
		return disjntSet.count();
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
