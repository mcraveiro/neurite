#ifndef NEURITE_SWC_HASH_POINT_HASH_HPP
#define NEURITE_SWC_HASH_POINT_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/swc/types/point.hpp"

namespace neurite {
namespace swc {

struct point_hasher {
public:
    static std::size_t hash(const point& v);
};

} }

namespace std {

template<>
struct hash<neurite::swc::point> {
public:
    size_t operator()(const neurite::swc::point& v) const {
        return neurite::swc::point_hasher::hash(v);
    }
};

}
#endif
