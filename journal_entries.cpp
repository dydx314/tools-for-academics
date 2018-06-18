#include <iostream>
#include <string>

using namespace std;

int main() {

	while (true) {
		string got, gave; double amt;
		cout << "what did you get? "; cin >> got;
				if (got == "break") break;
		cout << "what did you give? "; cin >> gave;
				if (gave == "break") break;
		cout << "transaction amount? "; cin >> amt;

		cout << "-----------------------------------" << endl;
		cout << "DR		" << got << "		" << amt << endl;
		cout << "  CR			" << gave << "		" << amt << endl;
	}
	return 0;

}