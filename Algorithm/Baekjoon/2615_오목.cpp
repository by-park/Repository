/*
2615 오목

Brute Force
 
틀렸던 점
- 무조건 가장 왼쪽 기준인데, 대각선 왼쪽 아래로 내려가는 경우 고려 안 함 

반례
6개가 나오는 경우는 무시하도록 해야함
https://www.acmicpc.net/board/view/83649
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 1
1 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 2
1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 2 2 0 0 0 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 1 2 1 1 1 1 1 1 1 0 0 0 0
1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 1 0 0 0 0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 2 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 2 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 2 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 2 0 0 2 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 2 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 2
0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 1 2 2 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 1 2 2 2

반례
5개하고 벽에 붙는 경우
https://www.acmicpc.net/board/view/82704
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

반례
내가 visited를 체크해버려서 시작점이었어야하는애가
패스되어버리는 경우 (한 숫자에서 여러 방향 갈래길 있을 떄) 
https://www.acmicpc.net/board/view/80305
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 2 2 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 2 2 2 2 2 2
0 0 0 0 0 0 0 0 0 0 0 0 0 2 2 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 2 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 2 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 2 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 2 2 2 2
*/
#include <stdio.h>

int board[19][19];
int visited[4][19][19];
int point[3];
int dx[4] = {1, 0, 1, -1};
int dy[4] = {0, 1, 1, 1}; 

int count(int color, int x, int y, int d, int depth)
{
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19) return depth;
	if (board[nx][ny] != color) return depth;
	visited[d][nx][ny] = 1;
	return count(color, nx, ny, d, depth+1);
}

int main(void)
{
	int ret = 0;

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19; i++) {
			if (!board[i][j]) continue;
			for (int d = 0; d < 4; d++) {
				if (visited[d][i][j]) continue;
				ret = count(board[i][j], i, j, d, 1);
				if (ret != 5) ret = 0;
				if (ret) {
					point[0] = board[i][j];
					point[1] = i;
					point[2] = j;
					break;	
				}				
			}
			if (ret) break;
		}
		if (ret) break;
	}
	
	printf("%d\n", point[0]);
	if (ret) printf("%d %d\n", point[1]+1, point[2]+1);
	return 0;
}
