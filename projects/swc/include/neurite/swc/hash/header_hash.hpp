#ifndef NEURITE_SWC_HASH_HEADER_HASH_HPP
#define NEURITE_SWC_HASH_HEADER_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/swc/types/header.hpp"

namespace neurite {
namespace swc {

struct header_hasher {
public:
    static std::size_t hash(const header& v);
};

} }

namespace std {

template<>
struct hash<neurite::swc::header> {
public:
    size_t operator()(const neurite::swc::header& v) const {
        return neurite::swc::header_hasher::hash(v);
    }
};

}
#endif
