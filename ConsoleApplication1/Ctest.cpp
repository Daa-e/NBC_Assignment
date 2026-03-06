#include <iostream>
using namespace std;

// 포션 관리 함수 (포인터 사용)
void setPotion(int menu, int* p_HPPotion, int* p_MPPotion, int status[]) {
    switch (menu) {
    case 1: // HP UP
        if (*p_HPPotion > 0) {
            status[0] += 20;
            (*p_HPPotion)--;
            cout << "HP 포션을 사용했습니다! (현재 HP: " << status[0] << ", 남은 포션: " << *p_HPPotion << ")\n";
        }
        else {
            cout << "HP 포션이 부족합니다!\n";
        }
        break;
    case 2: // MP UP
        if (*p_MPPotion > 0) {
            status[1] += 20;
            (*p_MPPotion)--;
            cout << "MP 포션을 사용했습니다! (현재 MP: " << status[1] << ", 남은 포션: " << *p_MPPotion << ")\n";
        }
        else {
            cout << "MP 포션이 부족합니다!\n";
        }
        break;
    case 3: // 공격력 UP
        status[2] *= 2; // 방법 1: 복합 대입 연산자
        cout << "공격력이 2배가 되었습니다! (현재 공격력: " << status[2] << ")\n";
        break;
    case 4: // 방어력 UP
        status[3] = status[3] + status[3]; // 방법 2: 덧셈 연산
        cout << "방어력이 2배가 되었습니다! (현재 방어력: " << status[3] << ")\n";
        break;
    case 6: // Level Up
        (*p_HPPotion)++;
        (*p_MPPotion)++;
        cout << "레벨 업! 포션을 각각 1개씩 추가 지급합니다.\n";
        break;
    }
}

int main() {
    // 1. 캐릭터 스탯 상자 만들기 (0:HP, 1:MP, 2:공격력, 3:방어력)
    int status[4] = { 0, 0, 0, 0 };
    int hpPotion = 5;
    int mpPotion = 5;

    // 2. 깐깐한 입력 검사
    while (true) {
        cout << "HP와 MP를 입력하세요 (각 50 초과): ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) break;
        cout << "잘못된 입력입니다. HP와 MP는 모두 50을 넘어야 합니다.\n";
    }

    while (true) {
        cout << "공격력과 방어력을 입력하세요 (각 0 초과): ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) break;
        cout << "잘못된 입력입니다. 공격력과 방어력은 0보다 커야 합니다.\n";
    }

    // 3. 스탯 관리 시스템 (메뉴판 무한 루프)
    int choice;
    while (true) {
        cout << "\n--- 메뉴판 ---\n";
        cout << "1. HP UP (포션)  2. MP UP (포션)\n";
        cout << "3. 공격력 UP     4. 방어력 UP\n";
        cout << "5. 현재 능력치   6. Level Up\n";
        cout << "0. 나가기\n";
        cout << "선택: ";
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }

        if (choice == 5) {
            cout << "\n[현재 스탯]\n";
            cout << "HP: " << status[0] << " | MP: " << status[1] << "\n";
            cout << "공격력: " << status[2] << " | 방어력: " << status[3] << "\n";
            cout << "HP 포션: " << hpPotion << "개 | MP 포션: " << mpPotion << "개\n";
        }
        else if (choice >= 1 && choice <= 6) {
            setPotion(choice, &hpPotion, &mpPotion, status);
        }
        else {
            cout << "올바른 번호를 선택해주세요.\n";
        }
    }

    return 0;
}