#include <ostream>
#include <boost/io/ios_state.hpp>
#include <boost/algorithm/string.hpp>
#include "neurite/swc/io/header_io.hpp"

inline std::string tidy_up_string(std::string s) {
    boost::replace_all(s, "\r\n", "<new_line>");
    boost::replace_all(s, "\n", "<new_line>");
    boost::replace_all(s, "\"", "<quote>");
    return s;
}

namespace neurite {
namespace swc {

std::ostream& operator<<(std::ostream& s, const header& v) {
    boost::io::ios_flags_saver ifs(s);
    s.setf(std::ios_base::boolalpha);
    s.setf(std::ios::fixed, std::ios::floatfield);
    s.precision(6);
    s.setf(std::ios::showpoint);

    s << " { "
      << "\"__type__\": " << "\"neurite::swc::header\"" << ", "
      << "\"original_source\": " << "\"" << tidy_up_string(v.original_source()) << "\"" << ", "
      << "\"creature\": " << "\"" << tidy_up_string(v.creature()) << "\"" << ", "
      << "\"region\": " << "\"" << tidy_up_string(v.region()) << "\"" << ", "
      << "\"field_or_layer\": " << "\"" << tidy_up_string(v.field_or_layer()) << "\"" << ", "
      << "\"type\": " << "\"" << tidy_up_string(v.type()) << "\"" << ", "
      << "\"contributor\": " << "\"" << tidy_up_string(v.contributor()) << "\"" << ", "
      << "\"reference\": " << "\"" << tidy_up_string(v.reference()) << "\"" << ", "
      << "\"raw\": " << "\"" << tidy_up_string(v.raw()) << "\"" << ", "
      << "\"extras\": " << "\"" << tidy_up_string(v.extras()) << "\"" << ", "
      << "\"soma_area\": " << v.soma_area() << ", "
      << "\"shrinkage_correction\": " << v.shrinkage_correction() << ", "
      << "\"version_number\": " << "\"" << tidy_up_string(v.version_number()) << "\"" << ", "
      << "\"version_date\": " << "\"" << tidy_up_string(v.version_date()) << "\"" << ", "
      << "\"scale\": " << "\"" << tidy_up_string(v.scale()) << "\""
      << " }";
    return(s);
}

} }
