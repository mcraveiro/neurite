#ifndef DOGEN_SWC_TEST_DATA_STRUCTURE_IDENTIFIER_TYPES_TD_HPP
#define DOGEN_SWC_TEST_DATA_STRUCTURE_IDENTIFIER_TYPES_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/swc/types/structure_identifier_types.hpp"

namespace dogen {
namespace swc {

class structure_identifier_types_generator {
public:
    structure_identifier_types_generator();

public:
    typedef dogen::swc::structure_identifier_types result_type;

public:
    static void populate(const unsigned int position, result_type& v);
    static result_type create(const unsigned int position);
    result_type operator()();

private:
    unsigned int position_;
};

} }

#endif
