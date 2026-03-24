#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	
	while (true) {
		stack<char> s;
		int flag = 0; // 0은 no가 출력 되지 않은 문장

		getline(cin, str);
		if (str == ".") {
			break;
		}

		for (int i = 0; i < str.size(); i++) {

			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}

			if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					cout << "no" << "\n";
					flag = 1;
					break;
				}
				else {
					s.pop();
				}
			}

			if (str[i] == ']') {
				if (s.empty() || s.top() != '[') {
					cout << "no" << "\n";
					flag = 1;
					break;
				}
				else {
					s.pop();
				}
			}

		}
		if (flag == 0) {
			if (s.empty()) {
				cout << "yes" << "\n";
			}
			else {
				cout << "no" << "\n";
			}
		}
	}

}