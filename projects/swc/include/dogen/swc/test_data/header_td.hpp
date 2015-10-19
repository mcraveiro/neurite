#ifndef DOGEN_SWC_TEST_DATA_HEADER_TD_HPP
#define DOGEN_SWC_TEST_DATA_HEADER_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/swc/types/header.hpp"

namespace dogen {
namespace swc {

class header_generator {
public:
    header_generator();

public:
    typedef dogen::swc::header result_type;

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
