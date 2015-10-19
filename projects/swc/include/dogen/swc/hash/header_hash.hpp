#ifndef DOGEN_SWC_HASH_HEADER_HASH_HPP
#define DOGEN_SWC_HASH_HEADER_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "dogen/swc/types/header.hpp"

namespace dogen {
namespace swc {

struct header_hasher {
public:
    static std::size_t hash(const header& v);
};

} }

namespace std {

template<>
struct hash<dogen::swc::header> {
public:
    size_t operator()(const dogen::swc::header& v) const {
        return dogen::swc::header_hasher::hash(v);
    }
};

}
#endif
