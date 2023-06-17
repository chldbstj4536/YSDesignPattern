#pragma once

#include <concepts>
#include <type_traits>
#include <tuple>

namespace YS::DesignPattern::Creational
{
    namespace
    {
        /**
         * @brief Set 가변타입변수에 Elemet가 존재하닌지에 대한 concept
         * 
         * @tparam Element 찾고자 하는 Type
         * @tparam Set Elemet에 대해 비교할 집합
         */
        template<typename Element, typename... Set>
        concept HasElement = (std::same_as<Element, Set> || ...);

        template<typename Factory, typename Product>
        concept ImplementCreateFunc = requires
        {
            // Factory::Create<Product>()
            {Factory::template Create<Product>()};
        };

        template<typename Factory, typename... Products>
        concept ImplementFactory = (ImplementCreateFunc<Factory, Products> && ...);
    }

    template<typename... AbstractProducts>
    class AbstractFactory
    {
    public:
        template<typename Factory, typename Product>
        requires HasElement<Product, AbstractProducts...> && ImplementFactory<Factory, AbstractProducts...>
        static Product* CreateProduct()
        {
            return Factory::template Create<Product>();
        }
        template<typename Factory, typename... Products>
        static std::tuple<Products* ...> CreateProducts()
        {
            return (std::make_tuple((CreateProduct<Factory, Products>()) ...));
        }
        template<typename Factory>
        static std::tuple<AbstractProducts* ...> CreateAllProducts()
        {
            return (std::make_tuple((CreateProduct<Factory, AbstractProducts>()) ...));
        }
    };
}