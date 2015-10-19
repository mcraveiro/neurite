#ifndef DOGEN_SWC_HASH_STANDARDISED_FILE_HASH_HPP
#define DOGEN_SWC_HASH_STANDARDISED_FILE_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "dogen/swc/types/standardised_file.hpp"

namespace dogen {
namespace swc {

struct standardised_file_hasher {
public:
    static std::size_t hash(const standardised_file& v);
};

} }

namespace std {

template<>
struct hash<dogen::swc::standardised_file> {
public:
    size_t operator()(const dogen::swc::standardised_file& v) const {
        return dogen::swc::standardised_file_hasher::hash(v);
    }
};

}
#endif
