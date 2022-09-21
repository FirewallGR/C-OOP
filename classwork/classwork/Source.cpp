#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>

void print(std::vector<int> vec) {
	for (auto& temp : vec) {
		std::cout << temp << std::endl;
	}
	std::cout << std::endl;
}
void main() {
	const int _MIN = -100;
	const int _MAX = 100;
	srand(time(0));
	std::vector<int> vec1(20, 0);


	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		*iterator = _MIN + rand() % (_MAX - _MIN + 1);
		std::cout << *iterator << std::endl;
	}

	std::cout << "MAX ELEMENT : " << *std::max_element(vec1.begin(), vec1.end()) << std::endl;
	std::cout << "MIN ELEMENT : " << *std::min_element(vec1.begin(), vec1.end()) << std::endl;

	std::sort(vec1.begin(), vec1.end());
	print(vec1);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		vec1.push_back(_MIN + rand() % (_MAX - _MIN + 1));
	}
	print(vec1);

	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		if (*iterator < 10) *iterator = 0;
	}
	print(vec1);
	std::cout << "test" << std::endl;
	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		iterator = std::find_if(iterator, vec1.end(), [&](int temp) {
			return (temp > 20);
			});
		std::cout << *iterator << std::endl;
	}
	std::cout << std::endl;
	/*for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		if (*iterator > 20) std::cout << *iterator << std::endl;
	}
	std::cout << std::endl;*/

	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		if (*iterator % 2 == 0) *iterator *= 3;
	}
	print(vec1);

	std::random_shuffle(vec1.begin(), vec1.end());
	print(vec1);

	bool flag = true;
	while (flag == true) {
		for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
			flag = false;
			if (*iterator > 50) {
				vec1.erase(iterator);
				flag = true;
				break;
			}
		}
	}
	print(vec1);

	std::cout << vec1.size() << std::endl;
	if (vec1.size() % 2 != 0) vec1.erase(vec1.begin() + vec1.size() - 1);
	else {
		for (auto iterator = vec1.rbegin(); iterator != vec1.rend(); ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}

	vec1.clear();

	if (vec1.empty()) std::cout << "vector is clear" << std::endl;
	else vec1.clear();
}