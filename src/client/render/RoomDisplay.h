// Generated by dia2code
#ifndef RENDER__ROOMDISPLAY__H
#define RENDER__ROOMDISPLAY__H

#include <string>
#include <vector>

namespace state {
  class Team;
  class Character;
  class Element;
  class Room;
  class Inventory;
}

#include "state/Element.h"
#include "state/Team.h"
#include "state/Room.h"
#include "state/Character.h"
#include "state/Inventory.h"

namespace render {

  /// class RoomDisplay - 
  class RoomDisplay {
    // Associations
    // Attributes
  public:
    std::string displayText     = "Dungeon Room";
    std::vector<std::string> listElementsinRoom     = {"res/background3vect.png","res/box.png","res/map.png"};
    std::vector<std::string> listCharacterIcon;
    std::vector<uint> listPosHero;
    std::vector<uint> listPosMonst;
    state::Team*  HeroTeam;
    state::Team*  MonsterTeam;
    std::string characterStats;
    state::Character* activeCharacter;
    // Operations
  public:
    std::vector<std::string> getRoomImages ();
    RoomDisplay (state::Element* e);
    ~RoomDisplay ();
    std::string getDisplayText ();
    std::string getCharacter ();
    std::string getCharacterStats ();
    RoomDisplay ();
    std::string getActiveName ();
    // Setters and Getters
  };

};

#endif
