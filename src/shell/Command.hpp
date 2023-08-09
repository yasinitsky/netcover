/**
 * Copyright (C) 2023 Yaroslav Yasynytskyi.
 * This file is part of Netcover.

 * Netcover is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3 of the License, or (at your option) any later
 * version.

 * Netcover is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.

 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SHELL_COMMAND_HPP
#define SHELL_COMMAND_HPP

#include "shell/Result.hpp"

#include <string>
#include <vector>

namespace shell {

class Command {
    public:
        using Arguments = std::vector<std::string>;

        virtual ~Command() { }

        virtual Result execute(Arguments &arguments) const = 0;
        
        const std::string &getName() const;
        const std::string &getDescription() const;

    private:
        const std::string m_name;
        const std::string m_description;
    
    protected:
        Command(const std::string &name, const std::string &description): m_name(name), m_description(description) { }
};

} // namespace shell

#endif // SHELL_COMMAND_HPP