#include <iostream>
#include <fstream>
#include <cstring>

template <class Type> class TCoords;

template <class Type>
class TCoords {
	Type x;
	Type y;
public:
	TCoords(Type x, Type y) : x(x), y(y) {
		this->x = x;
		this->y = y;
	}
	
	TCoords() : x(0), y(0) {
		x = y = 0;
	}


	template <class Type2>
	TCoords(const TCoords<Type2>& coord) {
		this->x = coord.x;
		this->y = coord.y;
	}

	template <class Type2>
	TCoords<Type>& operator=(const TCoords<Type2>& coord) {
		if (this == &coord) return *this;
		this->x = coord.x;
		this->y = coord.y;
		return *this;
	}

	TCoords<Type>& operator+(TCoords<Type> coord) {
		TCoords<Type> temp(this->x + coord.x, this->y + coord.y);
		return temp;
	}

	TCoords<Type>& operator-(TCoords<Type> coord) {
		TCoords<Type> temp(this->x - coord.x, this->y - coord.y);
		return temp;
	}


	void print() {
		std::cout << x << " " << y << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, TCoords& coord) {
		out << "X: " << coord.x << "\nY: " << coord.y << std::endl;
		return out;
	}
};


int main() {
	TCoords<int> coords1(1, 0);
	coords1.print();
	std::cout << coords1;

	TCoords<int> coords2(0, 1);

	TCoords<int> coords3 = coords1 + coords2;

	coords3.print();
	std::cout << coords3;

}