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

	// 배열 값 출력
	cout << "==================삭제전================\n";
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << "\n";
	}
	cout << "Size: " << vec1.size() << "\n";

	// 배열의 원소 갯수 만큼 삭제
	for (int i = 0; i < vecSize; i++) {
		vec1.pop_back();
	}

	// 확인을 위해 하나 다시넣기
	vec1.push_back(30);

	cout << "==================삭제후================\n";
	// 배열 값 출력
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << "\n";
	}
	cout << "Size: " << vec1.size() << "\n";

	return 0;
}