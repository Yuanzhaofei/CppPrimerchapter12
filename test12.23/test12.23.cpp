#include<cstring>
#include<iostream>
#include<iterator>
#include<string>
#include<vector>

using namespace std;
int main() {
//test12.24
	string s;
	cin >> s;
	char * cp = new char[s.size() + 1]();
	for (size_t i = 0; i != s.size(); ++i) {
		cp[i] = s[i];
	}
	for (size_t i = 0; i != s.size(); ++i) {
		cout << cp[i] << ends;
	}
	system("pause");
	return 0;
}
