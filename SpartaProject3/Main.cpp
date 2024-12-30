#include <iostream>
#include <string>
#include <vector>
#include <crtdbg.h>		// 메모리누수확인
#include "SimpleVector.h"

#if _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#define malloc(s) _malloc_dbg(s,_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

using namespace std;

int main() {
	
	// int
	{
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

		// 원소 9개 추가.
		cout << "==================9개추가후 현재 size, capacity확인================\n";
		for (int i = 0; i < 9; i++) {
			vec1.push_back(i + 10);
		}

		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		// 크기가 모두 채워진 상태에서 추가할시 용량 추가.
		cout << "==================1개 추가 -> 기존 capacity초과 추가시 size, capacity확인================\n";
		vec1.push_back(99);

		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		cout << "==================5개 추가 -> 기존 capacity초과 추가시 size, capacity확인================\n";
		for (int i = 0; i < 5; i++) {
			vec1.push_back(i + 10);
		}

		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		cout << "==================현재까지 쌓은 16개의 데이터 확인================\n";
		vecSize = vec1.size();

		for (int i = 0; i < vecSize; i++) {
			cout << "[ " << vec1[i] << " ] ";
			if ((i + 1) % 10 == 0 || (i + 1) == vecSize) {
				cout << "\n";
			}
		}
		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		cout << "==================정렬 후 확인================\n";
		vec1.sortData();

		for (int i = 0; i < vecSize; i++) {
			cout << "[ " << vec1[i] << " ] ";
			if ((i + 1) % 10 == 0 || (i + 1) == vecSize) {
				cout << "\n";
			}
		}

		// vector확인
		/*vector<int> vect = { 1, 2, 3, 4, 5 };
		for (int i = 0; i < vect.size(); i++) {
			cout << vect[i] << "\n";
			vect.pop_back();
		}*/
	}

	-_CrtDumpMemoryLeaks();

	return 0;
}