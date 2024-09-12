#include <stdio.h>
#include <string>
#include "Parser.cpp"

void main() {
	std::string expression;

	std::cout << "enter expression: " << std::endl;
	std::cin >> expression;

	Parser parser(expression);
	parser.printPostfix();

	std::cout << std::endl;

	std::cout << "result : " << parser.calculate() << std::endl;

	/*CustomStack<int> stack;
	stack.push(10);
	stack.push(2);
	stack.push(3);

	std::cout << stack.top() << std::endl;

	stack.pop();

	std::cout << stack.top() << std::endl;
	*/
}