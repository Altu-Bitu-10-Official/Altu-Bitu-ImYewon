#include <iostream>
#include <set>

using namespace std;

int setOfString(string str) {

	set<string> s;

	for (int i = 0; i < str.length(); i++) {
		string temp;
		for (int j = i; j < str.length(); j++) {
			temp += str[j]; 
			s.insert(temp);
		}
	}

	return s.size();
}

int main() {

	string str;

	cin >> str;

	cout << setOfString(str);

	return 0;
}
