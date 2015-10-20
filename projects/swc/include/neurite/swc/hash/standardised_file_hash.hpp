#ifndef NEURITE_SWC_HASH_STANDARDISED_FILE_HASH_HPP
#define NEURITE_SWC_HASH_STANDARDISED_FILE_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/swc/types/standardised_file.hpp"

namespace neurite {
namespace swc {

struct standardised_file_hasher {
public:
    static std::size_t hash(const standardised_file& v);
};

} }

namespace std {

template<>
struct hash<neurite::swc::standardised_file> {
public:
    size_t operator()(const neurite::swc::standardised_file& v) const {
        return neurite::swc::standardised_file_hasher::hash(v);
    }
};

}
#endif
