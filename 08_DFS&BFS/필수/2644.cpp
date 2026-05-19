#include <iostream>
#include <queue>

using namespace std;

int n, m; // n: 전체 사람 수, m: 관계의 개수
bool visited[101] = {false, };
int graph[101][101] = {0, };
int n1, n2; // 촌수를 계산해야하는 두사람
int dist[101]; // 촌수를 저장하는 배열

void bfs() {
	queue<int> q;

	q.push(n1);
	visited[n1] = true;
	dist[n1] = 0; // 자기 자신과는 0촌

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1 && visited[i] == false) {
				visited[i] = true;
				dist[i] = dist[now] + 1; // 촌수 + 1
				q.push(i);
			}
		}
	}

}

int main() {
	cin >> n;
	cin >> n1 >> n2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;

		graph[parent][child] = graph[child][parent] = 1;
	}

	bfs();

	if (visited[n2] == true) {
		cout << dist[n2];
	} 
	else {
		cout << -1;
	}

	return 0;
}