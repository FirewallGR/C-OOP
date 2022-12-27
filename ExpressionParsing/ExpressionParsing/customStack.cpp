#include <stdio.h>
#include <string>
template <class T>
class CustomStack {
private:
	T *data;
	int Top;
	int size;
public:
	CustomStack() {
		data = new T[1];
		size = 1;
		Top = -1;
	}
	CustomStack(int size) {
		size < 1 ? throw std::string("Negative value") : NULL;
		data = new T[size];
		this.size = size;
		Top = -1;
	}

	void push(T value) {
		if (isFull()) {
			T* newData = new T[size + 1];
			for (int i = 0; i < size; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			size++;
		}
		Top++;
		data[Top] = value;
	}

	T check() {
		isEmpty() ? throw std::string("Stack is empty") : NULL;
		return data[Top];
	}

	void pop() {
		isEmpty() ? throw std::string("Stack is empty") : NULL;
		T* newData = new T[size - 1];
		for (int i = 0; i < size - 1; i++) {
			newData[i] = data[i];
		}
		Top--;
		size--;
		delete[] data;
		data = newData;
	}

	bool isFull() {
		return Top == size - 1;
	}

	bool isEmpty() {
		return Top == -1;
	}
	
	T top() {
		return data[Top];
	}
};