#include <iostream>

using namespace std;

int main(void)
{
	// 선언과 동시에 초기화
	int arr1[3] = { 1, 2, 3 };

	// 선언 후 개별 초기화 (임의 접근)
	int arr2[3];
	arr2[0] = 10;
	arr2[1] = 20;
	arr2[2] = 30;

	cout << "arr1: " << arr1[0] << ", " << arr1[1] << ", " << arr1[2] << endl;
	cout << "arr1: " << arr2[0] << ", " << arr2[1] << ", " << arr2[2] << endl;

	return 0;
}