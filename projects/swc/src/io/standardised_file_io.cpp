#include <ostream>
#include "dogen/swc/io/point_io.hpp"
#include "dogen/swc/io/header_io.hpp"
#include "dogen/swc/io/standardised_file_io.hpp"

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::optional<dogen::swc::header>& v) {
    s << "{ " << "\"__type__\": " << "\"boost::optional\"" << ", ";

    if (v)
        s << "\"data\": " << *v;
    else
        s << "\"data\": ""\"<empty>\"";
    s << " }";
    return s;
}

}

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::list<dogen::swc::point>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace dogen {
namespace swc {

std::ostream& operator<<(std::ostream& s, const standardised_file& v) {
    s << " { "
      << "\"__type__\": " << "\"dogen::swc::standardised_file\"" << ", "
      << "\"header\": " << v.header() << ", "
      << "\"points\": " << v.points()
      << " }";
    return(s);
}

} }
