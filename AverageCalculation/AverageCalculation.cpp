#include <iostream>
using namespace std;


int calcuateAverage(int score1, int score2, int score3, int score4)
{
	int sum = score1 + score2 + score3 + score4;
	return sum / 4;
}



int main(void)
{
	int score1 = 80, score2 = 90, score3 = 85, score4 = 70;
	cout << "Æò±Õ Á¡¼ö: " << calcuateAverage(score1, score2, score3, score4) << endl;
	return 0;
}