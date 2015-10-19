#ifndef DOGEN_SWC_IO_POINT_IO_HPP
#define DOGEN_SWC_IO_POINT_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "dogen/swc/types/point.hpp"

namespace dogen {
namespace swc {

std::ostream&
operator<<(std::ostream& s,
     const dogen::swc::point& v);

} }

#endif
