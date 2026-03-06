#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion, int status[])
{
    switch (count)
    {
        case 1:
            if (*p_HPPotion > 0)
            {
                status[0] += 20;
                (*p_HPPotion)--;
                cout << "HP 포션을 사용했습니다. (현재 HP: " << status[0] << ", 남은 포션: " << *p_HPPotion << ")\n";
            }
            else
            {
                cout << "HP 포션이 부족합니다." << endl;
            }
            break;
        case 2:
            if (*p_MPPotion > 0)
            {
                status[1] += 20;
                (*p_MPPotion)--;
                cout << "MP 포션을 사용했습니다. (현재 MP: " << status[1] << ", 남은 포션: " << *p_MPPotion << ")\n";
            }
            else
            {
                cout << "MP 포션이 부족합니다." << endl;
            }
            break;
            
        case 3:
            status[2] *= 2;
            cout << "공격력이 2배로 증가했습니다. (현재 공격력: " << status[2] << ")\n";
            break;
        case 4:
            status[3] *= 2;
            cout << "방어력이 2배로 증가했습니다. (현재 방어력: " << status[3] << ")\n";
            break;

        case 6:
            (*p_HPPotion)++;
            (*p_MPPotion)++;
            cout << "Level UP! 포션을 각각 1개씩 추가 지급합니다 현재 포션은:.\n";
            cout << "[현재 포션] HP 포션: " << *p_HPPotion << "개 | MP 포션: " << *p_MPPotion << "개\n";
            break;
    }
}

int main(void)
{
	int status[4] = { 0, 0, 0, 0 };
    int HpPotion = 5;
    int MpPotion = 5;

    while (true)
    {
        cout << "HP와 MP를 입력하세요 (각 50 초과): ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) break;
        cout << "잘못된 입력입니다. HP와 MP는 모두 50을 넘어야 합니다.\n";
    }

    while (true)
    {
        cout << "공격력과 방어력을 입력하세요 (각 0 초과): ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) break;
        cout << "잘못된 입력입니다. 공격력과 방어력은 0보다 커야 합니다.\n";
    }

    int menu;
    while (true)
    {
        cout << "\n==============================================" << endl;
        cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP" << endl;
        cout << "5.현재 능력치 / 6.Level Up / 0.게임 나가기" << endl;
        cin >> menu;

        if (menu == 0) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }

        if (menu == 5) {
            cout << "\n[현재 스탯]\n";
            cout << "HP: " << status[0] << " | MP: " << status[1] << "\n";
            cout << "공격력: " << status[2] << " | 방어력: " << status[3] << "\n";
            cout << "HP 포션: " << HpPotion << "개 | MP 포션: " << MpPotion << "개\n";
        }
        else if (menu >= 1 && menu <= 6)
        {
            setPotion(menu, &HpPotion, &MpPotion, status);
        }
        else
        {
            cout << "올바른 번호를 선택해주세요.\n";
        }
    }
    return 0;
}