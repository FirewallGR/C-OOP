#include <iostream>
#include <fstream>
class Coordinates {
	int x, y;
public:
	Coordinates(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
	Coordinates() {
		x = y = 0;
	}

	Coordinates(const Coordinates &coord) {
		this->x = coord.x;
		this->y = coord.y;
	}

	Coordinates& operator=(Coordinates coord) {
		if (this == &coord) return *this;
		Coordinates temp(coord.x, coord.y);
		return temp;
	}
	Coordinates& operator+(Coordinates coord) {
		Coordinates temp(this->x + coord.x, this->y + coord.y);
		return temp;
	}

	Coordinates& operator-(Coordinates coord) {
		Coordinates temp(this->x - coord.x, this->y - coord.y);
		return temp;
	}
	std::ostream& operator<<(std::ostream& out) {
		out << "X: " << this->x << "\nY: " << this->y << std::endl;
		return out;
	}

	void print() {
		std::cout << x << " " << y << std::endl;
	}
};

int main() {

}