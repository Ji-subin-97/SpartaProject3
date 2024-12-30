#include <iostream>
#include <string>
#include <vector>
#include <crtdbg.h>		// �޸𸮴���Ȯ��
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

		// ���� 9�� �߰�.
		cout << "==================9���߰��� ���� size, capacityȮ��================\n";
		for (int i = 0; i < 9; i++) {
			vec1.push_back(i + 10);
		}

		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		// ũ�Ⱑ ��� ä���� ���¿��� �߰��ҽ� �뷮 �߰�.
		cout << "==================1�� �߰� -> ���� capacity�ʰ� �߰��� size, capacityȮ��================\n";
		vec1.push_back(99);

		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		cout << "==================5�� �߰� -> ���� capacity�ʰ� �߰��� size, capacityȮ��================\n";
		for (int i = 0; i < 5; i++) {
			vec1.push_back(i + 10);
		}

		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		cout << "==================������� ���� 16���� ������ Ȯ��================\n";
		vecSize = vec1.size();

		for (int i = 0; i < vecSize; i++) {
			cout << "[ " << vec1[i] << " ] ";
			if ((i + 1) % 10 == 0 || (i + 1) == vecSize) {
				cout << "\n";
			}
		}
		cout << "Size: " << vec1.size() << "\n";
		cout << "Capacity: " << vec1.capacity() << "\n";

		cout << "==================���� �� Ȯ��================\n";
		vec1.sortData();

		for (int i = 0; i < vecSize; i++) {
			cout << "[ " << vec1[i] << " ] ";
			if ((i + 1) % 10 == 0 || (i + 1) == vecSize) {
				cout << "\n";
			}
		}

		// vectorȮ��
		/*vector<int> vect = { 1, 2, 3, 4, 5 };
		for (int i = 0; i < vect.size(); i++) {
			cout << vect[i] << "\n";
			vect.pop_back();
		}*/
	}

	-_CrtDumpMemoryLeaks();

	return 0;
}