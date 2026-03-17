#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNum (string num) {
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		if (isdigit(num[i])) {
			sum += num[i] - '0'; // char to int (아스키 코드여서 0 빼주기). 소스코드 참고했습니다.
		}
	}
	return sum;
}

bool comp(const string& g1, const string& g2) { //false면 swap
	if (g1.size() != g2.size()) {
		return g1.size() < g2.size();
	}
	if (sumNum(g1) != sumNum(g2)) {
		return sumNum(g1) < sumNum(g2);
	}
	return
		g1 < g2;
}

int main() {

	int n;
	cin >> n;
	
	vector<string> guitar(n);

	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	sort(guitar.begin(), guitar.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << guitar[i] << '\n';
	}
	return 0;
}