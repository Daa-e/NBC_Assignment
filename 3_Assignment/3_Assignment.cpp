#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Item
{
private:
    string name_;
    int price_;

public:
    Item() : name_(""), price_(0) {}
    Item(string name, int price) : name_(name), price_(price) {}

    void PrintInfo() const
    {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
    int GetPrice() const { return price_; }
};

bool compareItemsByPrice(const Item& a, const Item& b)
{
    return a.GetPrice() < b.GetPrice();
}

template <typename T>
class Inventory
{
private:
    T* pItems_;     // 동적 배열을 가리키는 포인터
    int capacity_;  // 최대 저장 공간의 크기
    int size_;      // 실제 저장된 아이템 개수

public:
    Inventory(int capacity = 10)
    {
        if (capacity <= 0)
        {
            capacity_ = 1;
        }
        else
        {
            capacity_ = capacity;
        }

        size_ = 0;
        pItems_ = new T[capacity_];
    }

    Inventory(const Inventory<T>& other)
    {
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i)
        {
            pItems_[i] = other.pItems_[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }

    ~Inventory()
    {
        if (pItems_ != nullptr)
        {
            delete[] pItems_;
            pItems_ = nullptr;
        }
    }

    void Assign(const Inventory<T>& other)
    {
        if (this == &other) return;

        delete[] pItems_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for(int i = 0; i < size_; ++i)
        {
            pItems_[i] = other.pItems_[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }

    void Resize(int newCapacity)
    {
        cout << "인벤토리 확장 중... (" << capacity_ << " -> " << newCapacity << ")" << endl;
        T* pNewItems = new T[newCapacity];

        for (int i = 0; i < size_; i++)
        {
            pNewItems[i] = pItems_[i];
        }

        delete[] pItems_;
        pItems_ = pNewItems;
        capacity_ = newCapacity;
    }

    void AddItem(const T& item)
    {
        if (size_ >= capacity_)
        {
            Resize(capacity_ * 2);
        }

        pItems_[size_] = item;
        size_++;
    }

    void RemoveLastItem()
    {
        if (size_ > 0)
        {
            size_--;
        }
        else
        {
            cout << "안내: 인벤토리가 비어있습니다." << endl;
        }
    }

    void SortItems()
    {
        if (size_ <= 1) return;
        sort(pItems_, pItems_ + size_, compareItemsByPrice);
        cout << "가격순으로 정렬되었습니다." << endl;
    }

    int GetSize() const
    {
        return size_;
    }
    int GetCapacity() const
    {
        return capacity_;
    }

    void PrintAllItems() const
    {
        if (size_ == 0)
        {
            cout << "인벤토리 상태: 비어있음" << endl;
            return;
        }

        cout << "--- 인벤토리 목록 (" << size_ << "/" << capacity_ << ") ---" << endl;
        for (int i = 0; i < size_; i++)
        {
            pItems_[i].PrintInfo();
        }
    }
};



int main()
{
    Inventory<Item> myInventory(2);
    int menu;

    while (true)
    {
        cout << "\n[1]추가 [2]삭제 [3]목록 [4]정렬 [0]종료 : ";
        cin >> menu;

        if (menu == 0) break;

        switch (menu)
        {
        case 1:
        {
            string name;
            int price;
            cout << "아이템 이름: ";
            cin >> name;
            cout << "가격: ";
            cin >> price;
            myInventory.AddItem(Item(name, price));
            break;
        }
        case 2:
            myInventory.RemoveLastItem();
            cout << "삭제 완료." << endl;
            break;
        case 3:
            myInventory.PrintAllItems();
            break;
        case 4:
            myInventory.SortItems();
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }
    return 0;
}