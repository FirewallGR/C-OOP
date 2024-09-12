#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <random>

void print(std::vector<std::vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print(std::vector<int> vec) {
	for (int j = 0; j < vec.size(); j++) {
		std::cout << vec[j] << " ";
	}
	std::cout << "\n" << std::endl;
}

void init(std::vector <std::vector <int>>* matrix) {
	(*matrix).assign(5, std::vector<int>(5));
	//srand(time(0));
	for (int i = 0; i < (*matrix).size(); i++) {
		for (int j = 0; j < (*matrix)[i].size(); j++) {
			if (j <= i) (*matrix)[j][i] = rand() % 9 + 1;
			else (*matrix)[i][j] = 0;
		}
	}
}

void init(std::vector<int>* vec1) {
	(*vec1).assign(5, 0);
	for (int i = 0; i < (*vec1).size(); i++) {
		(*vec1)[i] = rand() % 9 + 1;
	}
}

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>> vec1, std::vector<std::vector<int>> vec2) {
	std::vector<std::vector<int>> result;
	result.assign(vec1.size(), std::vector<int>(vec1.size()));
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j < vec1.size(); j++) {
			result[i][j] = 0;
			for (int k = 0; k < vec1.size(); k++) {
				result[i][j] += vec1[i][k] * vec2[k][j];
			}
		}
	}
	return result;
}

std::vector<int> multiply(std::vector<std::vector<int>> vec1, std::vector<int> vec2) {
	std::vector<int> result(5, 0);
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j < vec1[i].size(); j++) {
			result[j] += vec1[i][j] * vec2[j];
		}
	}

	return result;
}

std::vector<std::vector<int>> add(std::vector<std::vector<int>> vec1, std::vector<std::vector<int>> vec2) {
	std::vector<std::vector<int>> result;
	result.assign(5, std::vector<int>(5));
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j < vec1.size(); j++) {
			result[i][j] = vec1[i][j] + vec2[i][j];
		}
	}
	return result;
}

std::vector<std::vector<int>> remove(std::vector<std::vector<int>> vec1, std::vector<std::vector<int>> vec2) {
	std::vector<std::vector<int>> result;
	result.assign(5, std::vector<int>(5));
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j < vec1.size(); j++) {
			result[i][j] = vec1[i][j] - vec2[i][j];
		}
	}
	return result;
}

void transpose(std::vector<std::vector<int>>* vec1) {
	for (int i = 0; i < (*vec1).size();++i) {
		for (int j = 0; j < (*vec1).size(); ++j) {
			std::swap((*vec1)[i][j], (*vec1)[j][i]);
		}
	}
}

void main() {
	std::vector <std::vector <int>> matrix;
	init(&matrix);
	std::cout << "Firts matrix:" << std::endl;
	print(matrix);

	std::vector <std::vector <int>> matrix2;
	init(&matrix2);
	std::cout << "Second matrix:" << std::endl;
	print(matrix2);

	std::vector <std::vector <int>> matrix3;
	matrix3 = multiply(matrix, matrix2);
	std::cout << "Multiplyed matrix:" << std::endl;
	print(matrix3);

	std::vector<int> vector;
	init(&vector);
	std::cout << "Column vector:" << std::endl;
	print(vector);

	std::vector<int> vector2;
	vector2 = multiply(matrix, vector);
	std::cout << "Matrix * column:" << std::endl;
	print(vector2);
	
	std::vector<std::vector<int>> matrix4;
	matrix4 = add(matrix, matrix2);
	std::cout << "matrix + matrix2" << std::endl;
	print(matrix4);

	std::vector<std::vector<int>> matrix5;
	matrix5 = remove(matrix, matrix2);
	std::cout << "matrix - matrix2:" << std::endl;
	print(matrix5);

}
