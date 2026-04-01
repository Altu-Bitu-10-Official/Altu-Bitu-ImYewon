#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

vector<int> getPrimes() {
	vector<int> primes(MAX + 1, 0);

	for (int i = 2; i < sqrt(MAX); i++) {
		if (primes[i] != 0) {
			continue;
		}

		for (int j = i * i; j <= MAX; j += i) {
			if (primes[j] == 0) {
				primes[j] = i;
			}
		}
	}
	return primes;
}

void sumOfPrimes(int n, vector<int>& primes) {
	for (int i = 3; i <= n / 2; i += 2) {
		if (primes[i] == 0 && primes[n - i] == 0) {
			cout << n << " = " << i << " + " << n - i << '\n';
			return;
		}
	}

	cout << "Goldbach's conjecture is wrong.";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> primes = getPrimes();

	int n;
	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}

		sumOfPrimes(n, primes);
	}
}