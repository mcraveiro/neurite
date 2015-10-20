#include "neurite/swc/test_data/point_td.hpp"
#include "neurite/swc/test_data/header_td.hpp"
#include "neurite/swc/test_data/standardised_file_td.hpp"

namespace {

neurite::swc::header
create_neurite_swc_header(const unsigned int position) {
    return neurite::swc::header_generator::create(position);
}

boost::optional<neurite::swc::header>
create_boost_optional_neurite_swc_header(unsigned int position) {
    boost::optional<neurite::swc::header> r(
        create_neurite_swc_header(position));
    return r;
}

neurite::swc::point
create_neurite_swc_point(const unsigned int position) {
    return neurite::swc::point_generator::create(position);
}

std::list<neurite::swc::point> create_std_list_neurite_swc_point(unsigned int position) {
    std::list<neurite::swc::point> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_neurite_swc_point(position + i));
    }
    return r;
}

}

namespace neurite {
namespace swc {

standardised_file_generator::standardised_file_generator() : position_(0) { }

void standardised_file_generator::
populate(const unsigned int position, result_type& v) {
    v.header(create_boost_optional_neurite_swc_header(position + 0));
    v.points(create_std_list_neurite_swc_point(position + 1));
}

standardised_file_generator::result_type
standardised_file_generator::create(const unsigned int position) {
    standardised_file r;
    standardised_file_generator::populate(position, r);
    return r;
}

standardised_file_generator::result_type*
standardised_file_generator::create_ptr(const unsigned int position) {
    standardised_file* p = new standardised_file();
    standardised_file_generator::populate(position, *p);
    return p;
}

standardised_file_generator::result_type
standardised_file_generator::operator()() {
    return create(position_++);
}

} }
