#ifndef NEURITE_SWC_HASH_STRUCTURE_IDENTIFIER_TYPES_HASH_HPP
#define NEURITE_SWC_HASH_STRUCTURE_IDENTIFIER_TYPES_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/swc/types/structure_identifier_types.hpp"

namespace std {

template<>
struct hash<neurite::swc::structure_identifier_types> {
public:
    size_t operator()(const neurite::swc::structure_identifier_types& v) const {
        return std::hash<unsigned int>()(static_cast<unsigned int>(v));
    }
};

}

#endif
