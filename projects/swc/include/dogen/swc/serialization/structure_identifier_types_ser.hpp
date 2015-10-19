#ifndef DOGEN_SWC_SERIALIZATION_STRUCTURE_IDENTIFIER_TYPES_SER_HPP
#define DOGEN_SWC_SERIALIZATION_STRUCTURE_IDENTIFIER_TYPES_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/nvp.hpp>
#include "dogen/swc/types/structure_identifier_types.hpp"

template<class Archive>
void serialize(Archive& ar, dogen::swc::structure_identifier_types& v, unsigned int /*version*/){
    using boost::serialization::make_nvp;
    ar & make_nvp("structure_identifier_types", v);
}

#endif
