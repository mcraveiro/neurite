#ifndef DOGEN_SWC_HASH_POINT_HASH_HPP
#define DOGEN_SWC_HASH_POINT_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "dogen/swc/types/point.hpp"

namespace dogen {
namespace swc {

struct point_hasher {
public:
    static std::size_t hash(const point& v);
};

} }

namespace std {

template<>
struct hash<dogen::swc::point> {
public:
    size_t operator()(const dogen::swc::point& v) const {
        return dogen::swc::point_hasher::hash(v);
    }
};

}
#endif
