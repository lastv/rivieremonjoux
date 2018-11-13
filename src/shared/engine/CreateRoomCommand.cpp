#include "CreateRoomCommand.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace engine;

CreateRoomCommand::CreateRoomCommand ():Command(){
  this->commandTypeId = CreateRoom;
  this->roomName = "0";
}
CreateRoomCommand::CreateRoomCommand (std::string roomName):Command(){
  this->commandTypeId = CreateRoom;
  this->roomName = roomName;
}
CreateRoomCommand::~CreateRoomCommand (){
}
CommandTypeId CreateRoomCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateRoomCommand::execute (state::State* state){
  if (state->getDungeonExists()){
    state::Dungeon* d = (state::Dungeon*) state->getGrid()->get(0,0);
    std::pair<bool,std::string> active = state->getOrder()[0];

    if (d->getRoomList().size() == 0){
      cout << "The Dungeon is Cleared" << endl;
    } else {
      std::map<std::string,state::Team*> roomlist =d->getRoomList();
      bool intermediary_isMonster = std::get<0>(active);
      std::string intermediary_activeName = std::get<1>(active);
      int pos;

      if (!intermediary_isMonster){
        pos = d->getHeroTeam()->getPos(intermediary_activeName);
      } else {
        pos = roomlist[this->roomName]->getPos(intermediary_activeName);
      }

      state->getChar()->add(state->getGrid()->get(0,0),"Dungeon");
      state->getGrid()->replaceElement(new state::Room(d->getHeroTeam(),roomlist[this->roomName],intermediary_isMonster,pos),"Room",0);
    }
  }
}