#include <concepts>
#include <type_traits>

namespace
{
    template<typename Element, typename... Set>
    concept HasElement = (std::same_as<Element, Set> || ...);

    template<typename Factory, typename Product>
    concept ImplementCreateFunc = requires(Product*& p)
    {
        {Factory::Create(p)};
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
    static void Create(Product*& product)
    {
        Factory::Create(product);
    }
};