#include "dogen/swc/test_data/structure_identifier_types_td.hpp"

namespace dogen {
namespace swc {

structure_identifier_types_generator::structure_identifier_types_generator() : position_(0) { }
void structure_identifier_types_generator::
populate(const unsigned int position, result_type& v) {
    v = static_cast<structure_identifier_types>(position % 8);
}

structure_identifier_types_generator::result_type
structure_identifier_types_generator::create(const unsigned int  position) {
    result_type r;
    structure_identifier_types_generator::populate(position, r);
    return r;
}

structure_identifier_types_generator::result_type
structure_identifier_types_generator::operator()() {
    return create(position_++);
}

} }
