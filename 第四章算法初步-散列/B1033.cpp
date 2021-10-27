

#include <iostream>
#include <string>
#include <stdlib.h>
#include <deque>

using namespace std;
int main() {
	deque <bool> hash(128, 0);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++) {
		char c1 = tolower(s1[i]);
		hash[c1] = true;
	}
	for (int i = 0; i < s2.size(); i++) {
		char c2 = tolower(s2[i]);
		if (hash['+'] && isupper(s2[i]))
			continue;
		if (hash[c2])
			continue;
		cout << s2[i];
	}
	cout << endl;
	return 0;
}
