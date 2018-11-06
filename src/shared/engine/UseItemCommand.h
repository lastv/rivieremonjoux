// Generated by dia2code
#ifndef ENGINE__USEITEMCOMMAND__H
#define ENGINE__USEITEMCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class UseItemCommand - 
  class UseItemCommand : public engine::Command {
    // Operations
  public:
    UseItemCommand ();
    ~UseItemCommand ();
    CommandTypeId getCommandTypeId ();
    void execute (state::State* state);
    // Setters and Getters
  };

};

#endif