#include "CreateDungeonCommand.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace engine;

CreateDungeonCommand::CreateDungeonCommand ():Command(){
  this->commandTypeId = CreateDungeon;
}
CreateDungeonCommand::~CreateDungeonCommand (){
}
CommandTypeId CreateDungeonCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateDungeonCommand::execute (state::State* state){
  std::ifstream fileread(this->dungeonListfile);
  std::vector<std::string> maps;
  for (std::string line; getline(fileread,line);){
    maps.push_back(line);
  }
  state::Village* v = (state::Village*) state->getGrid()->get(0,0);
  if(v->getTeam()->getTeam().size() == 0){
    cout << "Your Team is Empty. You need at least one Hero to challenge a Dungeon" << endl;
  } else {
    state->getChar()->add(state->getGrid()->get(0,0),"Village");
    state->getGrid()->replaceElement(new state::Dungeon(maps,v->getTeam()),"Dungeon",0);
  }

}