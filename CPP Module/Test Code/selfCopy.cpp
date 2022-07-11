class A {
public:
	A() {}
	A(int n) : a(n) {a = n + 1;}
private:
	int a;
};

int main(void) {
	A a(1);
	a = a;
}