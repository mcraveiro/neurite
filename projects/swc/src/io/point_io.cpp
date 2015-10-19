#include <ostream>
#include <boost/io/ios_state.hpp>
#include "dogen/swc/io/point_io.hpp"
#include "dogen/swc/io/structure_identifier_types_io.hpp"

namespace dogen {
namespace swc {

std::ostream& operator<<(std::ostream& s, const point& v) {
    boost::io::ios_flags_saver ifs(s);
    s.setf(std::ios_base::boolalpha);
    s.setf(std::ios::fixed, std::ios::floatfield);
    s.precision(6);
    s.setf(std::ios::showpoint);

    s << " { "
      << "\"__type__\": " << "\"dogen::swc::point\"" << ", "
      << "\"sample_number\": " << v.sample_number() << ", "
      << "\"unparsed_structure_identifier\": " << v.unparsed_structure_identifier() << ", "
      << "\"structure_identifier\": " << v.structure_identifier() << ", "
      << "\"x\": " << v.x() << ", "
      << "\"y\": " << v.y() << ", "
      << "\"z\": " << v.z() << ", "
      << "\"radius\": " << v.radius() << ", "
      << "\"parent_sample\": " << v.parent_sample()
      << " }";
    return(s);
}

} }
