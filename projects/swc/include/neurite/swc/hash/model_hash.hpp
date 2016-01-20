#ifndef NEURITE_SWC_HASH_MODEL_HASH_HPP
#define NEURITE_SWC_HASH_MODEL_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/swc/types/model.hpp"

namespace neurite {
namespace swc {

struct model_hasher {
public:
    static std::size_t hash(const model& v);
};

} }

namespace std {

template<>
struct hash<neurite::swc::model> {
public:
    size_t operator()(const neurite::swc::model& v) const {
        return neurite::swc::model_hasher::hash(v);
    }
};

}
#endif
