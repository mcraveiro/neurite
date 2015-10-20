#include <ostream>
#include "neurite/swc/io/point_io.hpp"
#include "neurite/swc/io/header_io.hpp"
#include "neurite/swc/io/standardised_file_io.hpp"

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::optional<neurite::swc::header>& v) {
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

inline std::ostream& operator<<(std::ostream& s, const std::list<neurite::swc::point>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace neurite {
namespace swc {

std::ostream& operator<<(std::ostream& s, const standardised_file& v) {
    s << " { "
      << "\"__type__\": " << "\"neurite::swc::standardised_file\"" << ", "
      << "\"header\": " << v.header() << ", "
      << "\"points\": " << v.points()
      << " }";
    return(s);
}

} }
