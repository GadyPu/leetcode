#define LOCAL
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char **d = NULL;
typedef struct P {
	int x, y;
}P;
int judge(char **board, int x, int y, char c) {
	int i, j;
	for(i = 0; i < 9; i++) {
		if(board[x][i] == c || board[i][y] == c) return 0;
	}
	for(i = x / 3 * 3; i <= x / 3 * 3 + 2; i++) {
		for(j = y / 3 * 3; j <= y / 3 * 3 + 2; j++) {
			if(board[i][j] == c) return 0;
		}
	}
	return 1;
}
int dfs_1(char **board, int x, int y) {
	int i;
	while(board[x][y] != '.' && (x < 8 || y < 8)) {
		if(y == 8) y = 0, x++; 
		else y++;
	}
	if(x == 8 && y == 8 && board[x][y] != '.') return 1;
	for(i = 1; i <= 9; i++) {
		if(judge(board, x, y, i + '0')) {
			board[x][y] = i + '0';
			if(dfs_1(board, x, y)) return 1;
			board[x][y] = '.';
		}
	}
	return 0;
}
int dfs(char **board, int tot, P *p) {
	int i, x, y;
	if(tot < 0) return 1;
	for(i = 1; i <= 9; i++) {
		x = p[tot].x, y = p[tot].y;
		if(judge(board, x, y, i + '0')) {
			board[x][y] = i + '0';
			if(dfs(board, tot - 1, p)) return 1;
			board[x][y] = '.';
		}
	}
	return 0;
}
void solveSudoku(char **board, int boardRowSize, int boardColSize) {
	if(!boardRowSize || !boardColSize) return;
	P p[81];
	int i, j, tot = 0;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(board[i][j] == '.') {
				p[tot].x = i, p[tot++].y = j;
			}
		}
	}
	dfs(board, tot - 1, p);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w+", stdout);
#endif
	int i;
	d = (char **)malloc(sizeof(char **) * 9);
	for(i = 0; i < 9; i++) {
		d[i] = (char *)malloc(sizeof(char *) * 10);
	}
	for(i = 0; i < 9; i++) {
		scanf("%s", d[i]);
	}
	solveSudoku(d, 9, 9);
	for(i = 0; i < 9; i++)
	for(i = 0; i < 9; i++) puts(d[i]);
	return 0;
}
