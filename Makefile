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

# This file is the main Makefile of the Netcover project
# It encapsulates build details under the next commands:
#		make run        - build and run netcover executable
#		make test       - build and run tests
# 		make cleanup    - cleanup build directory
# Another recipes shouldn't be used via make tool

include Makefile.common

.PHONY: run
run: build
	@./$(BUILD_ROOT)/$(shell $(MODULE_MAKE) get-executable MODULE=src)

.PHONY: build
build:
	@$(MODULE_MAKE) build-executable MODULE=src

.PHONY: test
test:
	@$(MODULE_MAKE) build-executable MODULE=test
	@./$(BUILD_ROOT)/$(shell $(MODULE_MAKE) get-executable MODULE=test)

.PHONY: cleanup
cleanup:
	$(RM) -rf $(BUILD_ROOT)