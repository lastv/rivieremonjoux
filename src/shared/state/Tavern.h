// Generated by dia2code
#ifndef STATE__TAVERN__H
#define STATE__TAVERN__H


namespace state {
  class Team;
  class Character;
  class StaticElements;
}

#include "StaticElements.h"
#include "Team.h"

namespace state {

  /// class Tavern - 
  class Tavern : public state::StaticElements {
    // Associations
    // Attributes
  private:
    Team* team;
    uint maxteam;
    // Operations
  public:
    void AddtoTeamTavern (Character* character, Team* team);
    void RemovefromTeamTavern (Character* character, Team* team);
    void isTeamFull ();
    void getStat (Character* character);
    void getSkills (Character* character);
    void setOrder (Character* character, uint pos);
    Tavern (Team* team, uint maxTeam);
    ~Tavern ();
    // Setters and Getters
  };

};

#endif
