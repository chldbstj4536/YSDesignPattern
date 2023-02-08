#pragma once

#include <memory>

namespace YS::DesignPattern::Creational
{
    template<class T>
    class Singletone
    {
    protected:
        Singletone() = default;
        Singletone(Singletone const &) = delete;
        Singletone(Singletone &&) = delete;
        ~Singletone() = default;
        Singletone& operator=(Singletone const &) = delete;
        Singletone& operator=(Singletone &&) = delete;

    public:
        static std::shared_ptr<T> GetInstance()
        {
            static std::shared_ptr<T> pInstance = std::make_shared<T>();
            return pInstance;
        }
    };
}