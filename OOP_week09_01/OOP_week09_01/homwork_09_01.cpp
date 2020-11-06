#include <iostream>

class MyData {
	std::string strNumber;
private:
	int number;
public:
	MyData(int data = 0, std::string str = "") : number(data), strNumber(str) {}
	operator int() { return number; }
	operator std::string() { return strNumber; }

	//Unary operator
	MyData operator++(int) { //postfix operation (indicated by dummy 'int')
		MyData temp(number);
		++(*this);
		return temp;
	}
	MyData operator++() { //prefix operation
		++number;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream&, MyData&);
};

// non-member operator<< function
std::ostream& operator<<(std::ostream& os, MyData& md) {
	return os << "This number is: " << md.strNumber;
}

int main() {
	MyData mydata(1, "one");

	std::string strNum = mydata;
	int intNum = mydata;

	std::cout << strNum << std::endl; // one
	std::cout << intNum << std::endl; // 1
	std::cout << mydata++ << std::endl; // 1
	std::cout << ++mydata << std::endl; // 3
	std::cout << mydata;

}