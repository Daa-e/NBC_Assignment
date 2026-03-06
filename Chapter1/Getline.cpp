#include <iostream>
#include <string>
using namespace std;

int main() {
    // 변수 선언
    string name;
    int age;
    float height;

    // 문자열 입력
    cout << "이름을 입력하세요: ";
    getline(cin, name);

    // 정수 입력
    cout << "나이를 입력하세요: ";
    cin >> age;

    // 실수 입력
    cout << "키를 입력하세요 (cm): ";
    cin >> height;

    // 출력으로 확인
    cout << "\n입력한 정보:" << endl;
    cout << "이름: " << name << endl;
    cout << "나이: " << age << endl;
    cout << "키: " << height << " cm" << endl;

    return 0;
}