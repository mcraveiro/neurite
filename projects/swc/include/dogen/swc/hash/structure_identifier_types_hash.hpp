#ifndef DOGEN_SWC_HASH_STRUCTURE_IDENTIFIER_TYPES_HASH_HPP
#define DOGEN_SWC_HASH_STRUCTURE_IDENTIFIER_TYPES_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "dogen/swc/types/structure_identifier_types.hpp"

namespace std {

template<>
struct hash<dogen::swc::structure_identifier_types> {
public:
    size_t operator()(const dogen::swc::structure_identifier_types& v) const {
        return std::hash<unsigned int>()(static_cast<unsigned int>(v));
    }
};

}

#endif
