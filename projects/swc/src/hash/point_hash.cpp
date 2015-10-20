#include "neurite/swc/hash/point_hash.hpp"
#include "neurite/swc/hash/structure_identifier_types_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}

namespace neurite {
namespace swc {

std::size_t point_hasher::hash(const point& v) {
    std::size_t seed(0);

    combine(seed, v.sample_number());
    combine(seed, v.unparsed_structure_identifier());
    combine(seed, v.structure_identifier());
    combine(seed, v.x());
    combine(seed, v.y());
    combine(seed, v.z());
    combine(seed, v.radius());
    combine(seed, v.parent_sample());

    return seed;
}

} }
