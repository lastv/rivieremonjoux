/**
 * @file UserDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserDB.hpp"
#include <string.h>
#include <iostream>

using namespace std;
using namespace server;

UserDB::UserDB() : idseq(1) {

}

const User* UserDB::getUser (int id) const {
    auto ite = users.find(id);
    if (ite == users.cend())
        return nullptr;
    return ite->second.get();
}
const std::vector<User*> UserDB::getAllUser()  const {
  std::vector<User*> output;
  auto ite = users.find(0);
  for (auto& x:this->users){
    //cout << "id: "<<x.first;
    output.push_back(x.second.get());
  }
  return output;
}

int UserDB::addUser (unique_ptr<User> user) {
    int id = idseq++;
    if (id<this->maxPlayers){
      user->playerId=id;
      users.insert(std::make_pair(id,std::move(user)));
      return id;
    } else {
      return -1;
    }
}

void UserDB::setUser (int id, unique_ptr<User> user) {
    users[id] = std::move(user);
    if (id > idseq) {
        idseq = id;
    }
}

void UserDB::removeUser (int id) {
    auto ite = users.find(id);
    if (ite == users.end())
        return;
    users.erase(ite);
    idseq--;
}
