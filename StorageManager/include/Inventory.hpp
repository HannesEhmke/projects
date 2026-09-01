#pragma once
#include <vector>
#include <optional>
#include <string>
#include "Item.hpp"

namespace storage {

class Inventory {
public:
    Inventory() = default;

    bool add_item(const Item& item);
    [[nodiscard]] std::optional<Item> find_item(const std::string& id) const;
    [[nodiscard]] const std::vector<Item>& get_all_items() const noexcept;
    bool update_stock(const std::string& id, int delta);

private:
    std::vector<Item> items_;
};

} // namespace storage