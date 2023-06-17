#include <iostream>
#include <format>
#include <YSDesignPattern/ysSingleton.hpp>
#include <YSDesignPattern/ysAbstractFactory.hpp>

namespace Singleton
{
    class foo : public YS::DesignPattern::Creational::Singleton<foo>
    {
    public:
        /**
         * @brief Singleton의 인터페이스에 맞게 생성자 추가
         * 
         * @param key Singleton 내부적으로 key를 넣어준다.
         */
        foo(PassKey<Singleton<foo>> key)
            : Singleton(key)
        {
            std::cout << "Create foo!\n";
        }
        virtual void Print()
        {
            std::cout << "This is foo's Print()." << std::endl;
        }
    };
}
namespace AbstractFactory
{
}

int main()
{
#pragma region Singleton Test
    {
        using namespace Singleton;
        std::cout << "========== Singleton Test ==========\n";
        std::cout << "foo::GetInstance()\n";
        foo::GetInstance()->Print();
    }
#pragma endregion

#pragma region AbstractFactory Test
    {
        using namespace AbstractFactory;
        using namespace YS::DesignPattern;
        std::cout << "========== Singleton Test ==========\n";
    }
#pragma region
}