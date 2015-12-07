#ifndef NEURITE_SWC_HASH_FILE_HASH_HPP
#define NEURITE_SWC_HASH_FILE_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/swc/types/file.hpp"

namespace neurite {
namespace swc {

struct file_hasher {
public:
    static std::size_t hash(const file& v);
};

} }

namespace std {

template<>
struct hash<neurite::swc::file> {
public:
    size_t operator()(const neurite::swc::file& v) const {
        return neurite::swc::file_hasher::hash(v);
    }
};

}
#endif
