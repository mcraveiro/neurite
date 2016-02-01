# -*- mode: dockerfile; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2016 Marco Craveiro <marco.craveiro@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#
FROM ubuntu:xenial

MAINTAINER Marco Craveiro version: 0.1

RUN apt-get update                            &&    \
    apt-get install -y                              \
            gcc-5                                   \
            cmake                                   \
            ninja-build                             \
            libboost-system-dev                     \
            libboost-exception-dev                  \
            libboost-serialization-dev              \
            libboost-log-dev                        \
            libboost-filesystem-dev                 \
            libboost-program-options-dev            \
            libboost-iostreams-dev                  \
            libcgal-dev                             \
            qtbase5-dev                             \
            libvtk6-dev                             \
            libvtk6-qt-dev                    &&    \
    apt-get clean
