#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <set>
#include "set.cpp"
#include <Windows.h>
#include <stack>


const int _MIN = -100;
const int _MAX = 100;

void print(std::vector<int> vec) {
	for (auto& temp : vec) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

void print(std::list<int> list) {
	for (auto& temp : list) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

void print(std::stack<int> *Stack) {
	std::list<int> list;
	if ((*Stack).empty()) {
		std::cout << "Stack is empty" << std::endl;
		return;
	}
	while (!((*Stack).empty())) {
		list.push_back((*Stack).top());
		(*Stack).pop();
	}
	std::cout << std::endl;
	for (int temp : list) {
		printf("\t| %3d |\t\n", temp);
	}
	std::cout << "\t_______\t" << std::endl;
	while (!list.empty()) {
		(*Stack).push(list.back());
		list.pop_back();
	}
}

int randomNumber(std::list<int> list) {
	srand(time(NULL));
	int numberPosition = rand() % list.size();
	auto listIterator = list.begin();
	std::advance(listIterator, numberPosition);
	return *listIterator;
}

void list() {
	std::cout << "Creating empty list..." << std::endl;
	std::list<int> list;
	std::cout << "Completed" << std::endl;

	std::cout << std::endl;


	std::cout << "Generating 5 random numbers" << std::endl;
	for (int i = 0; i < 5; i++) {
		list.push_back(_MIN + rand() % (_MAX - _MIN + 1));
	}

	std::cout << std::endl;

	std::cout << "First number is: " << list.front() << std::endl;

	std::cout << std::endl;

	std::cout << "Adding 2 elements in front of list" << std::endl;
	for (int i = 0; i < 2; i++)
		list.push_front(_MIN + rand() % (_MAX - _MIN + 1));
	print(list);

	std::cout << std::endl;

	std::cout << "Erase fourth element" << std::endl;
	auto iter = list.begin();
	std::advance(iter, 3);
	list.erase(iter);
	print(list);

	std::cout << std::endl;

	std::cout << "Adding element in 3 random positions" << std::endl;
	srand(time(NULL));
	int number = randomNumber(list);
	for (int i = 0; i < 3; i++) {
		int insertPosition = rand() % list.size();
		iter = list.begin();
		std::advance(iter, insertPosition);
		list.insert(iter, number);
		Sleep(1000);
	}
	print(list);

	std::cout << std::endl;

	std::cout << "Deleting last element" << std::endl;
	list.pop_back();
	print(list);

	std::cout << std::endl;

	std::cout << "Deleting first element" << std::endl;
	list.pop_front();
	print(list);

	std::cout << std::endl;

	std::cout << "Adding random element in center 2 times" << std::endl;
	iter = list.begin();
	std::advance(iter, list.size() / 2);
	list.insert(iter, 2, randomNumber(list));
	print(list);

	std::cout << std::endl;

	std::cout << "Deleting duplicates" << std::endl;
	list.sort();
	list.unique();
	print(list);

	std::cout << std::endl;

	std::cout << "Clearing list..." << std::endl;
	list.clear();

	std::cout << std::endl;

	if (list.empty())
		std::cout << "List is empty" << std::endl;

	std::cout << std::endl;
}

void vector() {
	srand(time(0));

	std::cout << "Creating vector with size 20 and zeros" << std::endl;
	std::vector<int> vec1(20, 0);
	print(vec1);

	std::cout << std::endl;

	std::cout << "Generating random numbers for vector" << std::endl;
	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		*iterator = _MIN + rand() % (_MAX - _MIN + 1);
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "Searching max and min elements:" << std::endl;

	std::cout << "MAX ELEMENT : " << *std::max_element(vec1.begin(), vec1.end()) << std::endl;

	std::cout << std::endl;

	std::cout << "MIN ELEMENT : " << *std::min_element(vec1.begin(), vec1.end()) << std::endl;

	std::cout << std::endl;

	std::cout << "Sorting vector..." << std::endl;

	std::sort(vec1.begin(), vec1.end());
	print(vec1);

	std::cout << std::endl;

	std::cout << "Pushing back 4 random numbers" << std::endl;

	for (int i = 0; i < 4; i++) {
		vec1.push_back(_MIN + rand() % (_MAX - _MIN + 1));
	}
	print(vec1);

	std::cout << std::endl;

	std::cout << "Changing elements below 10 on 0" << std::endl;

	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		if (*iterator < 10) *iterator = 0;
	}
	print(vec1);


	std::cout << std::endl;

	std::cout << "Searching elements above 20" << std::endl;
	/*for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		iterator = std::find_if(iterator, vec1.end(), [&](int temp) {
			return (temp > 20);
			});
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;*/
	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		if (*iterator > 20) std::cout << *iterator << " ";
	}

	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "Increasing 2 times even numbers" << std::endl;

	for (auto iterator = begin(vec1); iterator != end(vec1); ++iterator) {
		if (*iterator % 2 == 0) *iterator *= 3;
	}
	print(vec1);

	std::cout << std::endl;

	std::cout << "Random shuffling" << std::endl;

	std::random_shuffle(vec1.begin(), vec1.end());
	print(vec1);

	std::cout << std::endl;

	std::cout << "Deleting elements above 50" << std::endl;

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

	std::cout << std::endl;

	std::cout << "Something" << std::endl;

	std::cout << vec1.size() << std::endl;
	if (vec1.size() % 2 != 0) vec1.erase(vec1.begin() + vec1.size() - 1);
	else {
		for (auto iterator = vec1.rbegin(); iterator != vec1.rend(); ++iterator) {
			std::cout << *iterator << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Clearing vector..." << std::endl;
	vec1.clear();

	if (vec1.empty()) std::cout << "vector is clear" << std::endl;
	else vec1.clear();

	std::cout << "\n\n" << std::endl;
}


void stack() {
	int action, number;
	bool isWorking = true;

	std::stack<int> Stack;

	std::cout << "1 - to push\n2 - to pop\n3 - to print\n4 - to clear\n5 - exit" << std::endl;
	while (isWorking) {
		std::cout << "Enter action: ";
		std::cin >> action;
		switch (action)
		{
		case 1:
			std::cout << "Enter number to push: ";
			std::cin >> number;
			Stack.push(number);
			break;
		case 2:
			if (Stack.empty()) {
				std::cout << "Stack is empty" << std::endl;
				break;
			}
			std::cout << "The element " << Stack.top() << " was removed" << std::endl;
			Stack.pop();
			break;
		case 3:
			print(&Stack);
			break;
		case 4:
			while (!Stack.empty()) {
				Stack.pop();
			}
			std::cout << "Stack was successfully cleared" << std::endl;
			break;
		case 5:
			isWorking = false;
			break;
		default:
			std::cout << "Incorrect action\nPlease, try again" << std::endl;
		}	
	}
}

void main() {
	vector();
	//list();
	stack();
}