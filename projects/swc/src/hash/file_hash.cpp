#include "neurite/swc/hash/file_hash.hpp"
#include "neurite/swc/hash/point_hash.hpp"
#include "neurite/swc/hash/header_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_boost_optional_neurite_swc_header(const boost::optional<neurite::swc::header>& v) {
    std::size_t seed(0);

    if (!v)
        return seed;

    combine(seed, *v);
    return seed;
}

inline std::size_t hash_std_list_neurite_swc_point(const std::list<neurite::swc::point>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

}

namespace neurite {
namespace swc {

std::size_t file_hasher::hash(const file& v) {
    std::size_t seed(0);

    combine(seed, hash_boost_optional_neurite_swc_header(v.header()));
    combine(seed, hash_std_list_neurite_swc_point(v.points()));

    return seed;
}

} }
