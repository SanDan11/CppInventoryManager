#include "item.hpp"


Item::Item(int id,
            const std::string& name,
            const std::string& category,
            double price,
            int quantity,
            const std::string& location)
    : id(id),
      name(name),
      category(category),
      price(price),
      quantity(quantity),
      location(location)
{    
}  