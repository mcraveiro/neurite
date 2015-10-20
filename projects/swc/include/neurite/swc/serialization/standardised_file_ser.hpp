#ifndef NEURITE_SWC_SERIALIZATION_STANDARDISED_FILE_SER_HPP
#define NEURITE_SWC_SERIALIZATION_STANDARDISED_FILE_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "neurite/swc/types/standardised_file.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(neurite::swc::standardised_file)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const neurite::swc::standardised_file& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, neurite::swc::standardised_file& v, unsigned int version);

} }

#endif
