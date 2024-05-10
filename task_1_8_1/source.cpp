#include <iostream>
#include <string>
#include <stack>


using namespace std;


int main() {
	stack<int> s;
	string command;
	while (true) {
		cin >> command;
		if (command == "push") {
			int val;
			cin >> val;
			s.push(val);
			cout << "ok" << endl;
		}
		if (command == "pop") {cout << s.top() << endl; s.pop();}
		if (command == "back") cout << s.top() << endl;
		if (command == "size") cout << s.size() << endl;
		if (command == "clear") {s = {}; cout << "ok" << endl;};
		if (command == "exit") {cout << "bye" << endl; return 0;}
	}

	return 0;
}
