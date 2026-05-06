#include <iostream>

using namespace std;

int main() {

	int n, k, answer = 0;
	cin >> n >> k;

	string s; 
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] != 'P') {
			continue;
		}

		for (int j = i - k; j <= i + k; j++) {
			if (0 <= j && j < n && s[j] == 'H') {
				s[j] = '0';
				answer++;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}