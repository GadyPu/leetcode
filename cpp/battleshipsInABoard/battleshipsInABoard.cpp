#include <bits/stdc++.h>
using namespace std;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };
class Solution {
public:
	int countBattleships(vector<vector<char>> &board) {
		int m = 0, ans = 0, n = board.size();
		if(!n) return 0;
		m = board[0].size();
		set<pair<int, int>> vis;
		function<void(int, int)> dfs = [&](int x, int y) {
			for(int i = 0; i < 4; i++) {
				int nx = dx[i] + x, ny = dy[i] + y;
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(board[nx][ny] != 'X' || vis.find({ nx, ny }) != vis.end()) continue;
				vis.insert({ nx, ny });
				dfs(nx, ny);
			}
		};
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(board[i][j] == 'X' && vis.find({ i, j }) == vis.end()) {
					dfs(i, j);
					ans++;
				}
			}
		}
		return ans;
	}
};
int main() {
	Solution d;
	vector<vector<char>> board = {
		{ 'X', '.', '.', 'X' },
		{ '.', '.', '.', 'X' },
		{ '.', '.', '.', 'X' },
		{ '.', 'X', '.', 'X' }
	};
	cout << d.countBattleships(board) << '\n';
	return 0;
}
