#include "Engine.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace engine;

//Constructor
Engine::Engine (){
}
Engine::Engine (state::State* state){
  this->currentState=state;
}
//Destructor
Engine::~Engine (){
}
//Operations
void Engine::setAdditionalParameters (std::string newParam){
  this->additionalParameters=newParam;
}
void Engine::setAdditionalParameters2 (std::string newParam){
  this->additionalParameters2=newParam;
}
state::State* Engine::getState (){
  return this->currentState;
}
void Engine::setRollback (bool rollback){
  this->rollback = rollback;
}
void Engine::addPassiveCommands (){
}
std::vector<std::tuple<int,std::string,std::string>> Engine::getCommandList (){
  return this->commandList;
}
void Engine::setCommandList (std::vector<std::tuple<int,std::string,std::string>> newCommandList){
  this->commandList=newCommandList;
}
void Engine::AddCommandTOList (int newCommand,std::string addParam1,std::string addParam2){
  std::tuple<int,std::string,std::string> command {newCommand,addParam1,addParam2};
  this->commandList.push_back(command);
}
void Engine::RemoveLastFromCommandList (){
  return this->commandList.pop_back();
}
void Engine::Chrono(){
  if (this->startChrono){
    this->chrono +=1;
    if (this->chrono*3 >= 48){
      this->invCommands=true;
    }
  }
}
void Engine::addCommand (int i ){
  AddCommandTOList(i,this->additionalParameters,this->additionalParameters2);
  if (i == 0){
    this->currentCommands.push_back( new CreateDungeonCommand());
  } else if (i == 3){
    this->currentCommands.push_back(new CreateVillageCommand());
  } else if (i == 8){
    this->currentCommands.push_back( new BackCommand());
  } else if (i == 1){
    this->currentCommands.push_back(new ChooseDungeonCommand(this->additionalParameters));
  } else if (i == 7){
    this->currentCommands.push_back(new CalculateActiveCommand());
  } else if (i == 2){
    this->currentCommands.push_back(new CreateRoomCommand());
    if (this->rollback && !this->startChrono){
      this->startChrono=true;
    }
  } else if (i == 4){
    if (this->additionalParameters.find("None")!=std::string::npos){
      this->currentCommands.push_back(new UseSkillCommand(this->additionalParameters2));
    } else {
      this->currentCommands.push_back(new UseSkillCommand(this->additionalParameters2,this->additionalParameters));
    }

  } else if (i == 6){
    this->currentCommands.push_back(new ChangeActiveCommand());
  } else if (i == 9){
    this->currentCommands.push_back(new ChangeRoomCommand());
  } else if (i == 10){
    this->currentCommands.push_back(new CreateTavernCommand());
  } else if (i == 11){
    this->currentCommands.push_back(new CheckCharaStateCommand());
  } else if (i == 12){
    this->currentCommands.push_back(new AddToTeam(this->additionalParameters));
  } else if (i == 13){
    this->currentCommands.push_back(new RemoveFromTeam(this->additionalParameters));
  }


}
void Engine::update (){
  bool changed = false;
  if (!this->invCommands){
    if (this->currentCommands.size()!=0){
      for (uint i=0; i<this->currentCommands.size();i++){
          sleep_for(nanoseconds(100));
          this->currentCommands[i]->execute(this->currentState);

      }
      changed = true;
      this->currentCommands.clear();
    }
  } else {
    cout << "Rollback command"<<endl;
  }
  if (changed){
    // this->currentState->Operator();
    // cout << "Engine ElementTab: "<< this->currentState->getGrid()->getSize() <<endl;
    // this->currentScene->stateChanged(this->currentState);
  }
}
