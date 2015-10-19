#ifndef DOGEN_SWC_IO_HEADER_IO_HPP
#define DOGEN_SWC_IO_HEADER_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "dogen/swc/types/header.hpp"

namespace dogen {
namespace swc {

std::ostream&
operator<<(std::ostream& s,
     const dogen::swc::header& v);

} }

#endif
