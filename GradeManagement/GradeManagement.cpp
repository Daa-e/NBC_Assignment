#include <iostream>

using namespace std;

int main(void)
{
	double score[5];

	cout << "첫 번째 학생의 점수를 입력하세요: ";
	cin >> score[0];

	cout << "두 번째 학생의 점수를 입력하세요: ";
	cin >> score[1];

	cout << "두 번째 학생의 점수를 입력하세요: ";
	cin >> score[2];

	cout << "세 번째 학생의 점수를 입력하세요: ";
	cin >> score[3];

	cout << "네 번째 학생의 점수를 입력하세요: ";
	cin >> score[4];

	double tot = score[0] + score[1] + score[2] + score[3] + score[4];
	double avg = tot / 5;

	cout << "학생들의 총점은: " << tot << "점입니다." << endl;
	cout << "학생들의 평균은: " << avg << "점입니다." << endl;

	return 0;
}