#include <iostream>
#include <vector>


using namespace std;


void dfs(const vector<vector<bool>> &paper, vector<vector<bool>> &visited, int r, int c) {
	if (r < 0 || 
     		r >= paper.size() || 
     		c < 0 || 
     		c >= paper[0].size() || 
		visited[r][c] ||
		!paper[r][c]) return ;

	visited[r][c] = true;

	dfs(paper, visited, r - 1, c);
	dfs(paper, visited, r, c - 1);
	dfs(paper, visited, r + 1, c);
	dfs(paper, visited, r, c + 1);
}


int countPieces(const vector<vector<bool>> &paper) {
	int res = 0;
	int rows = paper.size();
	int cols = paper[0].size();
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (!visited[i][j] && paper[i][j]) {
				++res;
				dfs(paper, visited, i, j);
			}
		}
	}
	return res;
}


int main() {
	int m, n;
	cin >> m >> n;
	
	vector<vector<bool>> paper(m, vector<bool>(n));
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) {
			char val;
			cin >> val;
			paper[i][j] = val == '#';
	}


	int pieces = countPieces(paper);
	cout << pieces << endl;

	return 0;
}
