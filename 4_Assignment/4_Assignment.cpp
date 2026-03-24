#include <iostream>
#include <vector>
#include <string>

// --- 물약 레시피 및 재고를 관리하는 클래스 ---
class PotionRecipe
{
private:
    std::string potionName_;      // 물약의 이름
    std::string coreIngredient_;  // 핵심 재료
    int stock_;                   // 현재 창고에 남은 개수
    const int MAX_STOCK = 3;      // 창고가 수용 가능한 최대 개수 3개로 고정

public:
    // 레시피 등록 시 이름과 재료를 받고, 재고는 3개로 초기화
    PotionRecipe(const std::string& potionName, const std::string& coreIngredient)
        : potionName_(potionName), coreIngredient_(coreIngredient), stock_(3){}

    const std::string& GetPotionName() const { return potionName_; }
    const std::string& GetCoreIngredient() const { return coreIngredient_; }
    int GetStock() const { return stock_; }

    // 물약 지급
    bool GivePotion()
    {
        if (stock_ > 0) // 재고가 1개 이상일 때만 지급 가능
        {
            stock_--;   // 지급 후 재고 1 감소
            return true;
        }
        return false;   // 재고가 없으면 실패 반환
    }

    // 공병 반환 받기
    bool ReturnPotion()
    {
        if (stock_ < MAX_STOCK) // 현재 재고가 최대치 3개 미만일 때만 추가 가능
        {
            stock_++;           // 반환 후 재고 1 증가
            return true;
        }
        return false;           // 이미 3개라면 더 이상 늘리지 않음
    }
};

// --- 공방 전체 운영 및 검색을 담당하는 클래스 ---
class AlchemyWorkshop
{
private:
    std::vector<PotionRecipe> recipes_; // 등록된 레시피들의 목록

public:
    // 새로운 레시피 객체를 생성하여 벡터에 저장
    void AddRecipe(const std::string& potionName, const std::string& coreIngredient)
    {
        recipes_.push_back(PotionRecipe(potionName, coreIngredient));
    }

    // 현재 창고에 있는 모든 물약의 상태를 화면에 출력
    void DisplayAllRecipes() const
    {
        if (recipes_.empty())
        {
            std::cout << "\n>> 등록된 레시피가 없습니다." << std::endl;
            return;
        }
        std::cout << "\n--- 현재 창고 상태 (최대 재고: 3) ---" << std::endl;
        for (const auto& r : recipes_)
        {
            std::cout << "[" << r.GetPotionName() << "] (재료: " << r.GetCoreIngredient()
                << ") | 재고: " << r.GetStock() << "개" << std::endl;
        }
    }

    // 통합 검색: 원본 데이터를 수정해야 하므로 포인터 타입을 반환함
    PotionRecipe* FindPotion(const std::string& keyword)
    {
        for (auto& r : recipes_)
        {
            // 입력한 검색어가 물약 이름과 같거나, 재료 이름과 같으면 해당 객체 주소 반환
            if (r.GetPotionName() == keyword || r.GetCoreIngredient() == keyword)
            {
                return &r;
            }
        }
        return nullptr; // 찾지 못했을 경우 안전하게 없음을 뜻하는 nullptr 반환
    }
};

int main()
{
    AlchemyWorkshop myWorkshop;
    int choice;

    while (true)
    {
        std::cout << "\n=== 연금술 공방 관리 시스템 ===" << std::endl;
        std::cout << "1. 레시피 추가\n2. 창고 목록 확인\n3. 물약 지급 (이름/재료 검색)\n4. 물약 반환\n0. 종료\n선택: ";

        // 숫자 이외의 입력이 들어왔을 때의 예외 처리
        if (!(std::cin >> choice))
        {
            std::cin.clear();              // 에러 상태 초기화
            std::cin.ignore(10000, '\n');  // 버퍼에 남은 잘못된 입력 제거
            std::cout << "숫자를 입력해주세요." << std::endl;
            continue;
        }

        if (choice == 0) break;
        std::cin.ignore(10000, '\n');

        if (choice == 1) // 레시피 추가 로직
        {
            std::string name, ingredient;
            std::cout << "물약 이름: "; std::getline(std::cin, name);
            std::cout << "핵심 재료: "; std::getline(std::cin, ingredient);
            myWorkshop.AddRecipe(name, ingredient);
            std::cout << ">> 레시피 등록 완료! (초기 재고 3개 지급)" << std::endl;
        }
        else if (choice == 2) // 목록 출력
        {
            myWorkshop.DisplayAllRecipes();
        }
        else if (choice == 3) // 물약 지급
        {
            std::string keyword;
            std::cout << "지급할 물약 이름 또는 재료 입력: ";
            std::getline(std::cin, keyword);

            // 통합 검색 함수 호출
            PotionRecipe* p = myWorkshop.FindPotion(keyword);
            if (p) // 검색 결과가 있을 때
            {
                if (p->GivePotion()) // 재고가 있어 지급 성공 시
                {
                    std::cout << ">> [" << p->GetPotionName() << "] 지급 완료. (잔여: " << p->GetStock() << ")" << std::endl;
                }
                else // 재고가 0일 때
                {
                    std::cout << ">> [경고] 재고가 부족하여 지급할 수 없습니다!" << std::endl;
                }
            }
            else
            {
                std::cout << ">> 검색 결과가 없습니다." << std::endl;
            }
        }
        else if (choice == 4) // 물약 반환
        {
            std::string keyword;
            std::cout << "반환할 물약 이름 또는 재료 입력: ";
            std::getline(std::cin, keyword);

            PotionRecipe* p = myWorkshop.FindPotion(keyword);
            if (p)
            {
                if (p->ReturnPotion()) // 최대치 미만이라 반환 성공 시
                {
                    std::cout << ">> [" << p->GetPotionName() << "] 반환 완료. (현재: " << p->GetStock() << ")" << std::endl;
                }
                else // 이미 3개일 때
                {
                    std::cout << ">> [안내] 창고가 이미 가득 찼습니다. (최대 3개 제한)" << std::endl;
                }
            }
            else
            {
                std::cout << ">> 검색 결과가 없습니다." << std::endl;
            }
        }
    }
    std::cout << "공방 문을 닫습니다..." << std::endl;
    return 0;
}