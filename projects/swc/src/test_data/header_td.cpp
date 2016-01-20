#include <sstream>
#include "neurite/swc/test_data/header_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace swc {

header_generator::header_generator() : position_(0) { }

void header_generator::
populate(const unsigned int position, result_type& v) {
    v.original_source(create_std_string(position + 0));
    v.creature(create_std_string(position + 1));
    v.region(create_std_string(position + 2));
    v.field_or_layer(create_std_string(position + 3));
    v.type(create_std_string(position + 4));
    v.contributor(create_std_string(position + 5));
    v.reference(create_std_string(position + 6));
    v.raw(create_std_string(position + 7));
    v.extras(create_std_string(position + 8));
    v.soma_area(create_double(position + 9));
    v.shrinkage_correction(create_double(position + 10));
    v.version_number(create_std_string(position + 11));
    v.version_date(create_std_string(position + 12));
    v.scale(create_std_string(position + 13));
}

header_generator::result_type
header_generator::create(const unsigned int position) {
    header r;
    header_generator::populate(position, r);
    return r;
}

header_generator::result_type*
header_generator::create_ptr(const unsigned int position) {
    header* p = new header();
    header_generator::populate(position, *p);
    return p;
}

header_generator::result_type
header_generator::operator()() {
    return create(position_++);
}

} }
