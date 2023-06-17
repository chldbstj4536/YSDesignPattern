#pragma once

#include <memory>
#include <iostream>
#include <ysUtility.hpp>

namespace YS::DesignPattern::Creational
{
    /**
     * @brief Singleton 패턴
     * 
     * 객체를 하나만 생성하고 사용하고자 할 때 사용하는 패턴
     * 
     * @tparam T Singleton 시킬 클래스를 CRTP로 감싸 Singleton<T>처럼 넣어준다.
     */
    template<class T>
    class Singleton : public PassKey<Singleton<T>>
    {
    protected:
/// @cond
        Singleton() = delete;
        Singleton(Singleton const &) = delete;
        Singleton(Singleton &&) = delete;
        ~Singleton() = default;
        Singleton& operator=(Singleton const &) = delete;
        Singleton& operator=(Singleton &&) = delete;
/// @endcond

        /**
         * @brief 외부에서는 생성하지 못하도록 하기 위해 PassKey를 받는 생성자
         */
        Singleton(PassKey<Singleton>) {}

    public:
        /**
         * @brief Singleton 인스턴스를 획득하는 함수
         * 
         * 인스턴스가 없다면 내부에서 생성한다.
         * 
         * @return std::shared_ptr<T> instance가 담긴 shared_ptr
         */
        static std::shared_ptr<T> GetInstance()
        {
            static std::shared_ptr<T> pInstance = std::make_shared<T>(PassKey<Singleton>());
            return pInstance;
        }
    };
}