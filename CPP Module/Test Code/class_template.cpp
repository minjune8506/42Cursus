#include <iostream>

template <typename T>
class Data {
public:
	void print();
	void setData(T data);
private:
	T data_;
};

template <typename T>
void Data<T>::print() {
	std::cout << "data : " << data_ << std::endl; 
}

template <typename T>
void Data<T>::setData(T data) {
	data_ = data;
}

int main(void) {
	Data<int> d_int;
	Data<char> d_char;
	Data<double> d_double;

	d_int.setData(10);
	d_char.setData('A');
	d_double.setData(42.42);

	d_int.print();
	d_char.print();
	d_double.print();
}
