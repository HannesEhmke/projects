#pragma once
#include <string>

namespace storage {

class Item {
public:
    Item(std::string id, std::string name, unsigned int stock, double price);

    [[nodiscard]] const std::string& get_id() const noexcept;
    [[nodiscard]] const std::string& get_name() const noexcept;
    [[nodiscard]] unsigned int get_stock() const noexcept;
    [[nodiscard]] double get_price() const noexcept;

    void add_stock(unsigned int amount) noexcept;
    bool remove_stock(unsigned int amount) noexcept;

private:
    std::string id_;
    std::string name_;
    unsigned int stock_;
    double price_;
};

} // namespace storage