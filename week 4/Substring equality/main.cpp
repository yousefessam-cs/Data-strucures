#include <iostream>

using namespace std;

class Solver {
	string s;
public:
	Solver(string s) : s(s) {
	}
	bool ask(int a, int b, int l) {
		return s.substr(a, l) == s.substr(b, l);
	}
};

int main() {
	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
