#ifndef NEURITE_SWC_IO_STRUCTURE_IDENTIFIER_TYPES_IO_HPP
#define NEURITE_SWC_IO_STRUCTURE_IDENTIFIER_TYPES_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "neurite/swc/types/structure_identifier_types.hpp"

namespace neurite {
namespace swc {

std::ostream& operator<<(std::ostream& s, const structure_identifier_types& v);

} }

#endif
