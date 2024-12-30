#include <iostream>
#include <string>
#include "SimpleVector.h"

using namespace std;

int main() {
	
	// int
	SimpleVector<int> vec1;
	
	for (int i = 0; i < 10; i++) {
		vec1.push_back(i + 10);
	}

	int vecSize = vec1.size();

	// �迭 �� ���
	cout << "==================������================\n";
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << "\n";
	}
	cout << "Size: " << vec1.size() << "\n";

	// �迭�� ���� ���� ��ŭ ����
	for (int i = 0; i < vecSize; i++) {
		vec1.pop_back();
	}

	// Ȯ���� ���� �ϳ� �ٽóֱ�
	vec1.push_back(30);

	cout << "==================������================\n";
	// �迭 �� ���
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << "\n";
	}
	cout << "Size: " << vec1.size() << "\n";

	return 0;
}