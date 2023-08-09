#include "commands/ExitCommand.hpp"

#include "misc/RuntimeData.hpp"

using namespace commands;

shell::Result ExitCommand::execute(Arguments &arguments) const {
    (void) arguments;

    misc::RuntimeData::runShell = false;
    return shell::Result{this->getName()};
}