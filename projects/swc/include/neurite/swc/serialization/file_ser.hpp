#ifndef NEURITE_SWC_SERIALIZATION_FILE_SER_HPP
#define NEURITE_SWC_SERIALIZATION_FILE_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "neurite/swc/types/file.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(neurite::swc::file)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const neurite::swc::file& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, neurite::swc::file& v, unsigned int version);

} }

#endif
