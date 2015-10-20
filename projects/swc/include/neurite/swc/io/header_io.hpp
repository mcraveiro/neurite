#ifndef NEURITE_SWC_IO_HEADER_IO_HPP
#define NEURITE_SWC_IO_HEADER_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "neurite/swc/types/header.hpp"

namespace neurite {
namespace swc {

std::ostream&
operator<<(std::ostream& s,
     const neurite::swc::header& v);

} }

#endif
