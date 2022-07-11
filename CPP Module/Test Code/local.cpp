#include <iostream>

using namespace std;

class A
{
public:
	A(string &s) : str(s) {}
	void print() {
		cout << str << endl;
	}
private:
	string str;
};

int main(void) {
		string s = "Hi";
		A a(s);
		a.print();
		s = "BYE";
		a.print();
}