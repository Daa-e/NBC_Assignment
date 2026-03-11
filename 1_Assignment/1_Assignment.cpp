#include <iostream>
#include <string>

class Player
{
public:
    virtual ~Player() {}

    virtual void attack() = 0;
};

class Warrior : public Player
{
public:
    void attack() override
    {
        std::cout << "전사: 검을 강하게 내려칩니다! [데미지: 20]" << std::endl;
    }
};

class Magician : public Player
{
public:
    void attack() override
    {
        std::cout << "마법사: 파이어볼을 쏩니다! [데미지: 18]" << std::endl;
    }
};

class Thief : public Player
{
public:
    void attack() override
    {
        std::cout << "도적: 단검으로 빠르게 2번 찌릅니다! [데미지: 12]" << std::endl;
    }
};

class Archer : public Player
{
public:
    void attack() override
    {
        std::cout << "궁수: 일반 화살을 날립니다! [데미지: 18]" << std::endl;
    }
};

int main(void)
{
    Player* player = nullptr;
    int menu = 0;

    std::cout << "=== 직업을 선택해주세요 ===" << std::endl;
    std::cout << "1.전사 / 2.마법사 / 3.도적 / 4.궁수" << std::endl;

    switch (menu)
    {
    case 1:
        player = new Warrior;
        break;
    case 2:
        player = new Magician;
        break;
    case 3:
        player = new Thief;
        break;
    case 4:
        player = new Archer;
        break;
    }

    std::cout << "\n[전투를 시작합니다.]" << std::endl;
    player->attack();

    delete player;
    player = nullptr;

    return 0;
}