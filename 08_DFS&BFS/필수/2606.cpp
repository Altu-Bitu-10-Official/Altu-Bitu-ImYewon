#include <iostream>
#include <queue>

using namespace std;

int n, m; // n: 컴퓨터 수, m: 연결된 컴퓨터 쌍
int graph[101][101] = {0, };
bool visited[101] = {false, };
int cnt = 0; // 감염된 컴퓨터 수

void bfs() {
	queue<int> q;

	q.push(1); // 1번 컴퓨터가 바이러그에 걸림
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}

}

int main() {

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
	}

	bfs();

	cout << cnt;

	return 0;
}