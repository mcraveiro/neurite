#ifndef DOGEN_SWC_SERIALIZATION_REGISTRAR_SER_HPP
#define DOGEN_SWC_SERIALIZATION_REGISTRAR_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace dogen {
namespace swc {

template<typename Archive>
void register_types(Archive& ar);

} }

#endif
