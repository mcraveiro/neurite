#ifndef DOGEN_SWC_SERIALIZATION_STANDARDISED_FILE_SER_HPP
#define DOGEN_SWC_SERIALIZATION_STANDARDISED_FILE_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "dogen/swc/types/standardised_file.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(dogen::swc::standardised_file)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const dogen::swc::standardised_file& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, dogen::swc::standardised_file& v, unsigned int version);

} }

#endif
