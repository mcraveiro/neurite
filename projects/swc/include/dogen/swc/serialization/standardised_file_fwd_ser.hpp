#ifndef DOGEN_SWC_SERIALIZATION_STANDARDISED_FILE_FWD_SER_HPP
#define DOGEN_SWC_SERIALIZATION_STANDARDISED_FILE_FWD_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/swc/types/standardised_file_fwd.hpp"

namespace boost {
namespace serialization {

template<class Archive>
void save(Archive& ar, const dogen::swc::standardised_file& v, unsigned int version);

template<class Archive>
void load(Archive& ar, dogen::swc::standardised_file& v, unsigned int version);

} }

#endif
