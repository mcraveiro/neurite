#ifndef NEURITE_SWC_IO_POINT_IO_HPP
#define NEURITE_SWC_IO_POINT_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "neurite/swc/types/point.hpp"

namespace neurite {
namespace swc {

std::ostream&
operator<<(std::ostream& s,
     const neurite::swc::point& v);

} }

#endif
