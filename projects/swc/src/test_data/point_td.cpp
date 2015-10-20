#include "neurite/swc/test_data/point_td.hpp"
#include "neurite/swc/test_data/structure_identifier_types_td.hpp"

namespace {

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

int create_int(const unsigned int position) {
    return position;
}

neurite::swc::structure_identifier_types
create_neurite_swc_structure_identifier_types(const unsigned int position) {
    return neurite::swc::structure_identifier_types_generator::create(position);
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace swc {

point_generator::point_generator() : position_(0) { }

void point_generator::
populate(const unsigned int position, result_type& v) {
    v.sample_number(create_unsigned_int(position + 0));
    v.unparsed_structure_identifier(create_int(position + 1));
    v.structure_identifier(create_neurite_swc_structure_identifier_types(position + 2));
    v.x(create_double(position + 3));
    v.y(create_double(position + 4));
    v.z(create_double(position + 5));
    v.radius(create_double(position + 6));
    v.parent_sample(create_int(position + 7));
}

point_generator::result_type
point_generator::create(const unsigned int position) {
    point r;
    point_generator::populate(position, r);
    return r;
}

point_generator::result_type*
point_generator::create_ptr(const unsigned int position) {
    point* p = new point();
    point_generator::populate(position, *p);
    return p;
}

point_generator::result_type
point_generator::operator()() {
    return create(position_++);
}

} }
