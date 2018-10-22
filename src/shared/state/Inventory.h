// Generated by dia2code
#ifndef STATE__INVENTORY__H
#define STATE__INVENTORY__H

#include <string>
#include <map>

namespace state {
  class Item;
}

#include "Item.h"

namespace state {

  /// class Inventory - 
  class Inventory {
    // Associations
    // Attributes
  private:
    std::map<std::string,int> listItems;
    uint inventorySize;
    // Operations
  public:
    Inventory (uint length);
    ~Inventory ();
    Inventory (uint length, std::map<std::string,int> inventory);
    void clearItem (std::string name);
    void addItem (std::string item);
    std::map<std::string,int> getInventory ();
    int getItemvalue (std::string name);
    void removeItem (std::string name, int valuetoremove);
    // Setters and Getters
  };

};

#endif