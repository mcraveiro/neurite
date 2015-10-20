#include "neurite/swc/hash/header_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}

namespace neurite {
namespace swc {

std::size_t header_hasher::hash(const header& v) {
    std::size_t seed(0);

    combine(seed, v.original_source());
    combine(seed, v.creature());
    combine(seed, v.region());
    combine(seed, v.field_or_layer());
    combine(seed, v.type());
    combine(seed, v.contributor());
    combine(seed, v.reference());
    combine(seed, v.raw());
    combine(seed, v.extras());
    combine(seed, v.soma_area());
    combine(seed, v.shrinkage_correction());
    combine(seed, v.version_number());
    combine(seed, v.version_date());
    combine(seed, v.scale());

    return seed;
}

} }
