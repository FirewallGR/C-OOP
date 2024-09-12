#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void print(std::vector<std::pair<std::string, float>> statuses) {
	for (auto iterator = begin(statuses); iterator != end(statuses); ++iterator) {
		std::cout << iterator->first << " : " << iterator->second << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<std::pair<std::string, float>> statuses(20 ,{"", 0});
	std::string modificators[] = {"Public", "Protected", "Private"};


	for (std::vector<std::pair<std::string, float>>::iterator iterator = begin(statuses); iterator != end(statuses); ++iterator) {
		*iterator = { modificators[rand() % 3], rand() % 100 };
	}

	print(statuses);

	for (auto iterator = begin(statuses); iterator != end(statuses); ++iterator) {
		iterator = std::find_if(iterator, statuses.end(), [&](std::pair<std::string, float>& temp) {
			return temp.first == "public";
			});
		iterator->second = 0;

	}

	print(statuses);
	return 0;
}