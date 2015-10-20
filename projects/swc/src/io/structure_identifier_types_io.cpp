#include <string>
#include <ostream>
#include <stdexcept>
#include "neurite/swc/io/structure_identifier_types_io.hpp"

namespace neurite {
namespace swc {

std::ostream& operator<<(std::ostream& s, const structure_identifier_types& v) {
    s << "{ " << "\"__type__\": " << "\"structure_identifier_types\", " << "\"value\": ";

    std::string attr;
    switch (v) {
    case structure_identifier_types::invalid:
        attr = "\"invalid\"";
        break;
    case structure_identifier_types::soma:
        attr = "\"soma\"";
        break;
    case structure_identifier_types::axon:
        attr = "\"axon\"";
        break;
    case structure_identifier_types::basal_dendrite:
        attr = "\"basal_dendrite\"";
        break;
    case structure_identifier_types::apical_dendrite:
        attr = "\"apical_dendrite\"";
        break;
    case structure_identifier_types::fork_point:
        attr = "\"fork_point\"";
        break;
    case structure_identifier_types::end_point:
        attr = "\"end_point\"";
        break;
    case structure_identifier_types::custom:
        attr = "\"custom\"";
        break;
    default:
        throw std::invalid_argument("Invalid value for structure_identifier_types");
    }
    s << attr << " }";
    return s;
}

} }
