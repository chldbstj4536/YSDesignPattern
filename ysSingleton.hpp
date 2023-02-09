#pragma once

#include <memory>
#include <iostream>
#include <ysUtility.hpp>

namespace YS::DesignPattern::Creational
{
    template<class T>
    class Singleton : public PassKey<Singleton<T>>
    {
    private:
        Singleton() { std::cout << "Singleton()\n"; }
    protected:
        Singleton(Singleton const &) = delete;
        Singleton(Singleton &&) = delete;
        ~Singleton() { std::cout << "~Singleton()\n"; }
        Singleton& operator=(Singleton const &) = delete;
        Singleton& operator=(Singleton &&) = delete;

        Singleton(PassKey<Singleton>) { std::cout << "Singleton(PassKey<Singleton>)\n"; }

    public:
        static std::shared_ptr<T> GetInstance()
        {
            static std::shared_ptr<T> pInstance = std::make_shared<T>(Singleton());
            return pInstance;
        }
    };
}