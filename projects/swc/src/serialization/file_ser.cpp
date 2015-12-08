#include <boost/serialization/nvp.hpp>
#include <boost/serialization/list.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/optional.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "neurite/swc/serialization/file_ser.hpp"
#include "neurite/swc/serialization/point_ser.hpp"
#include "neurite/swc/serialization/header_ser.hpp"

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const neurite::swc::file& v,
    const unsigned int /*version*/) {
    ar << make_nvp("header", v.header_);
    ar << make_nvp("points", v.points_);
}

template<typename Archive>
void load(Archive& ar,
    neurite::swc::file& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("header", v.header_);
    ar >> make_nvp("points", v.points_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const neurite::swc::file& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, neurite::swc::file& v, unsigned int version);

template void save(archive::text_oarchive& ar, const neurite::swc::file& v, unsigned int version);
template void load(archive::text_iarchive& ar, neurite::swc::file& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const neurite::swc::file& v, unsigned int version);
template void load(archive::binary_iarchive& ar, neurite::swc::file& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const neurite::swc::file& v, unsigned int version);
template void load(archive::xml_iarchive& ar, neurite::swc::file& v, unsigned int version);

} }