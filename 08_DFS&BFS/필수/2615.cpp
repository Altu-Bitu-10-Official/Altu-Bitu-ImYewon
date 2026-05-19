#include <iostream>

using namespace std;

const int n = 20;
int board[n][n];
// 오른쪽, 아래, 오른쪽 위, 오른쪽 아래
int dy[4] = {1, 0, 1, 1}; // 행 : 기존 x축
int dx[4] = {0, 1, -1, 1}; // 열 : 기존 y축
int color; 

bool isValid(int x, int y) { // 오목 판 위에 존재하는지
	return x >= 1 && x <= 19 && y >= 1 && y <= 19;
}

void game() {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (board[i][j] == 0) { // 1, 2가 아니라 0이면 그냥 진행
				continue;
			}
			else {
				color = board[i][j]; // 1 또는 2 라면 그 수를 color에 저장
			}
			for (int d = 0; d < 4; d++) {

				int cnt = 1; // cnt 1부터

				int x = i + dx[d]; 
				int y = j + dy[d];

				while (isValid(x, y) && board[x][y] == board[i][j]) {
					x += dx[d]; 
					y += dy[d];

					cnt++;
				}

				if (cnt == 5) {
					cout << color << '\n';
					cout << i << ' ' << j << '\n';
					return;
				}

				}
			}
		}
cout << 0;
}


int main() {

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			cin >> board[i][j];
		}
	}

	game();

	return 0;
}