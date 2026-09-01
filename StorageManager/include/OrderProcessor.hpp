#pragma once
#include <vector>
#include <string>
#include "Inventory.hpp"

namespace storage {

struct OrderEntry {
    std::string item_id;
    unsigned int quantity;
};

class OrderProcessor {
public:
    // Gibt true zurück, wenn alle Artikel ausreichend auf Lager sind und gebucht wurden
    static bool process_order(Inventory& inventory, const std::vector<OrderEntry>& order);
};

} // namespace storage