# Copyright (C) 2023 Yaroslav Yasynytskyi.
# This file is part of Netcover.
#
# Netcover is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3 of the License, or (at your option) any later
# version.
#
# Netcover is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <http://www.gnu.org/licenses/>.

# Include main.cpp only if used like executable
# Tests use static library produced by this module, so don't compile main.cpp in this case
SOURCE_FILES 	= $(if $(filter $(MAKECMDGOALS),build-executable),main.cpp,)
INCLUDE_DIRS	= .
EXECUTABLE		= netcover
STATIC_LIBRARY	= netcover_static