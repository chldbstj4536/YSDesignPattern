#include <concepts>
#include <type_traits>
#include <tuple>

namespace
{
    template<typename Element, typename... Set>
    concept HasElement = (std::same_as<Element, Set> || ...);

    template<typename Factory, typename Product>
    concept ImplementCreateFunc = requires
    {
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