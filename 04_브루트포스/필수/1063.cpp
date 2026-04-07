#include <iostream>

using namespace std;

void cmdChange(int& x, int& y, string cmd) {
	x = 0, y = 0;
	if (cmd == "R") {
		x = 1;
	}
	if (cmd == "L") {
		x = -1;
	}
	if (cmd == "B") {
		y = -1;
	}
	if (cmd == "T") {
		y = 1;
	}
	if (cmd == "RT") {
		x = 1;
		y = 1;
	}
	if (cmd == "LT") {
		x = -1;
		y = 1;
	}
	if (cmd == "RB") {
		x = 1;
		y = -1;
	}
	if (cmd == "LB") {
		x = -1;
		y = -1;
	}
}

void moveChess(int& king_x, int& king_y, int& stone_x, int& stone_y, string cmd) {
	int x, y;
	cmdChange(x, y, cmd);

	int next_king_x = king_x + x;
	int next_king_y = king_y + y;

	if (next_king_x < 0 || next_king_x >= 8 || next_king_y < 0 || next_king_y >= 8) {
		return;
	} 

	if (next_king_x == stone_x && next_king_y == stone_y) {
		int next_stone_x = stone_x + x;
		int next_stone_y = stone_y + y;

		if (next_stone_x < 0 || next_stone_x >= 8 || next_stone_y < 0 || next_stone_y >= 8) {
			return;
		}
		stone_x = next_stone_x;
		stone_y = next_stone_y;
	}
	king_x = next_king_x;
	king_y = next_king_y;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string king, stone;
	int n;

	cin >> king >> stone >> n;

	int king_x = king[0] - 'A';
	int king_y = king[1] - '1';
	int stone_x = stone[0] - 'A';
	int stone_y = stone[1] - '1';

	while (n--) {
		string cmd;
		cin >> cmd;

		moveChess(king_x, king_y, stone_x, stone_y, cmd);
	}

	cout << char(king_x + 'A') << king_y + 1 << '\n';
	cout << char(stone_x + 'A') << stone_y + 1 << '\n';
}