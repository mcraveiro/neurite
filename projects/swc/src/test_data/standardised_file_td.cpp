#include "dogen/swc/test_data/point_td.hpp"
#include "dogen/swc/test_data/header_td.hpp"
#include "dogen/swc/test_data/standardised_file_td.hpp"

namespace {

dogen::swc::header
create_dogen_swc_header(const unsigned int position) {
    return dogen::swc::header_generator::create(position);
}

boost::optional<dogen::swc::header>
create_boost_optional_dogen_swc_header(unsigned int position) {
    boost::optional<dogen::swc::header> r(
        create_dogen_swc_header(position));
    return r;
}

dogen::swc::point
create_dogen_swc_point(const unsigned int position) {
    return dogen::swc::point_generator::create(position);
}

std::list<dogen::swc::point> create_std_list_dogen_swc_point(unsigned int position) {
    std::list<dogen::swc::point> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_dogen_swc_point(position + i));
    }
    return r;
}

}

namespace dogen {
namespace swc {

standardised_file_generator::standardised_file_generator() : position_(0) { }

void standardised_file_generator::
populate(const unsigned int position, result_type& v) {
    v.header(create_boost_optional_dogen_swc_header(position + 0));
    v.points(create_std_list_dogen_swc_point(position + 1));
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
