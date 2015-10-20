#ifndef NEURITE_SWC_SERIALIZATION_HEADER_SER_HPP
#define NEURITE_SWC_SERIALIZATION_HEADER_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "neurite/swc/types/header.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(neurite::swc::header)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const neurite::swc::header& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, neurite::swc::header& v, unsigned int version);

} }

#endif
