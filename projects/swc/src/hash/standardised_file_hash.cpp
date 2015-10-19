#include "dogen/swc/hash/point_hash.hpp"
#include "dogen/swc/hash/header_hash.hpp"
#include "dogen/swc/hash/standardised_file_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_boost_optional_dogen_swc_header(const boost::optional<dogen::swc::header>& v) {
    std::size_t seed(0);

    if (!v)
        return seed;

    combine(seed, *v);
    return seed;
}

inline std::size_t hash_std_list_dogen_swc_point(const std::list<dogen::swc::point>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

}

namespace dogen {
namespace swc {

std::size_t standardised_file_hasher::hash(const standardised_file& v) {
    std::size_t seed(0);

    combine(seed, hash_boost_optional_dogen_swc_header(v.header()));
    combine(seed, hash_std_list_dogen_swc_point(v.points()));

    return seed;
}

} }
