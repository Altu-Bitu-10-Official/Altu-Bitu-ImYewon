#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int answer = arr[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		if (answer % arr[i] != 0) {
			answer = (answer / arr[i] + 1) * arr[i];
		}
	}

	cout << answer;

	return 0;
}