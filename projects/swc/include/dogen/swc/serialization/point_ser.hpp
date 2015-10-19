#ifndef DOGEN_SWC_SERIALIZATION_POINT_SER_HPP
#define DOGEN_SWC_SERIALIZATION_POINT_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "dogen/swc/types/point.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(dogen::swc::point)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const dogen::swc::point& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, dogen::swc::point& v, unsigned int version);

} }

#endif
