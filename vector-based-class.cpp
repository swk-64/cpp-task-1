#include <vector>
#include <string>
#include <iostream>


template<typename T>
class SecureVector {
	std::vector<T> data;
	std::string key;

public:
	void resetKey(std::string oldKey, std::string newKey) {
		if (this->key == oldKey) {
			this->key = newKey;
		}
	}
	void push_back(T value, std::string key) {
		if (this->key == key) {
			data.push_back(value);
		}
		else {
			std::cout << "Invalid key" << std::endl;
		}
	}

	void remove(int index, std::string key) {
		if (this->key == key) {
			data.erase(data.begin() + index);
		}
		else {
			std::cout << "Invalid key" << std::endl;
		}
	}

	int size(std::string key) {
		if (this->key == key) {
			return data.size();
		}
		else {
			std::cout << "Invalid key" << std::endl;
		}
	}

	T access(int index, std::string key) {
		if (this->key == key) {
			return data[index];
		}
		else {
			std::cout << "Invalid key" << std::endl;
		}
	}

	SecureVector(std::string key) {
		this->key = key;
	}
};
