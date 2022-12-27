#include <stdio.h>
#include <string>
#include <map>
#include <stack>
#include <iostream>
#include "CustomStack.cpp"

class Parser {
private:
	std::string infixExpression;
	std::string postfixExpression;
	std::map<char, int> operationsPriority = {
		{'(', 0},
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
		{'^', 3},
		{'~', 4}
	};

	bool isDigit(char c) {
		if ('0' <= c && c <= '9') return true;
		else return false;
	}

	bool containsKey(char c) {
		for (std::pair<char, int> pair : operationsPriority) {
			if (pair.first == c) return true;
		}
		return false;
	}


	std::string parseNumber(std::string expression, int* position) {
		std::string number = "";
		for (; (*position) < expression.length(); (*position)++) {
			char expressionChar = expression[(*position)];
			if (isDigit(expressionChar))
				number += expressionChar;
			else {
				(*position)--;
				break;
			}
		}
		return number;
	}

	double execute(char operation, double first, double second) {
		switch (operation) {
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '*':
			return first * second;
		case '/':
			return first / second;
		}
	}
public:
	Parser(std::string expression) {
		infixExpression = expression;
		postfixExpression = toPostfix();
	}

	int getOperationPriority(char operation) {
		for (std::pair<char, int> pair : operationsPriority) {
			if (pair.first == operation) return pair.second;
		}
	}

	std::string toPostfix() {
		std::string tempPostfixExpression = "";
		CustomStack<char> stack; 
		for (int i = 0; i < infixExpression.length(); i++) {
			char expressionChar = infixExpression[i];
			if (isDigit(expressionChar))
				tempPostfixExpression += parseNumber(infixExpression, &i) + " ";
			else if (expressionChar == '(')
				stack.push(expressionChar);
			else if (expressionChar == ')') {
				while (!stack.isEmpty() && stack.top() != '(') {
					tempPostfixExpression += stack.top();
					stack.pop(); // удаление всего между (****)
				}
				stack.pop(); //удаление (
			}
			else if (containsKey(expressionChar)) {
				char operation = expressionChar;
				while (!stack.isEmpty() && getOperationPriority(stack.top()) >= getOperationPriority(operation)) {
					tempPostfixExpression += stack.top();
					stack.pop();
				}
				stack.push(operation);
			}
		}
		while (!stack.isEmpty()) {
			tempPostfixExpression += stack.top();
			stack.pop();
		}
		return tempPostfixExpression;
	}

	double calculate() {
		CustomStack<double> numbers;
		int counter = 0;
		for (int i = 0; i < postfixExpression.length(); i++) {
			char expressionChar = postfixExpression[i];
			if (isDigit(expressionChar)) {
				std::string number = parseNumber(postfixExpression , &i);
				numbers.push(std::stol(number));
			}
			else if (containsKey(expressionChar)) {
				counter++;
				double second = numbers.isEmpty() ? 0 : numbers.top();
				numbers.pop();
				double first = numbers.isEmpty() ? 0 : numbers.top();
				numbers.pop();
				numbers.push(execute(expressionChar, first, second));

				std::cout << counter << ") " << first << " " << expressionChar << " " << second << " = " << numbers.top() << std::endl;
			}

		}
		return numbers.top();
	}


	void printPostfix() {
		std::cout << postfixExpression << std::endl;
	}
};