#ifndef COMMANDS_HELP_COMMAND_HPP
#define COMMANDS_HELP_COMMAND_HPP

#include "shell/Command.hpp"

namespace commands {

class ExitCommand : public shell::Command {
    public:
        ExitCommand() : Command("exit", "exit from the netcover shell") { }
        shell::Result execute(Arguments &arguments) const override;
};

} // namespace commands

#endif // COMMANDS_HELP_COMMAND_HPP