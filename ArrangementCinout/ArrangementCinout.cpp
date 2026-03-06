#include <iostream>

using namespace std;

int main(void)
{
	int arr[3];

	cout << "첫 번째 정수를 입력하세요: ";
	cin >> arr[0];

	cout << "두 번째 정수를 입력하세요: ";
	cin >> arr[1];

	cout << "세 번째 정수를 입력하세요: ";
	cin >> arr[2];

	cout << "입력한 값" << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;

	return 0;
}