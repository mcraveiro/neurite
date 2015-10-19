#ifndef DOGEN_SWC_TEST_DATA_POINT_TD_HPP
#define DOGEN_SWC_TEST_DATA_POINT_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/swc/types/point.hpp"

namespace dogen {
namespace swc {

class point_generator {
public:
    point_generator();

public:
    typedef dogen::swc::point result_type;

public:
    static void populate(const unsigned int position, result_type& v);
    static result_type create(const unsigned int position);
    result_type operator()();

private:
    unsigned int position_;
public:
    static result_type* create_ptr(const unsigned int position);
};

} }

#endif
