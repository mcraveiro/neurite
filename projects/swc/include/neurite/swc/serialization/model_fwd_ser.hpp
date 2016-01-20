#ifndef NEURITE_SWC_SERIALIZATION_MODEL_FWD_SER_HPP
#define NEURITE_SWC_SERIALIZATION_MODEL_FWD_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "neurite/swc/types/model_fwd.hpp"

namespace boost {
namespace serialization {

template<class Archive>
void save(Archive& ar, const neurite::swc::model& v, unsigned int version);

template<class Archive>
void load(Archive& ar, neurite::swc::model& v, unsigned int version);

} }

#endif
