#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "dogen/swc/serialization/point_ser.hpp"
#include "dogen/swc/serialization/structure_identifier_types_ser.hpp"

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const dogen::swc::point& v,
    const unsigned int /*version*/) {
    ar << make_nvp("sample_number", v.sample_number_);
    ar << make_nvp("unparsed_structure_identifier", v.unparsed_structure_identifier_);
    ar << make_nvp("structure_identifier", v.structure_identifier_);
    ar << make_nvp("x", v.x_);
    ar << make_nvp("y", v.y_);
    ar << make_nvp("z", v.z_);
    ar << make_nvp("radius", v.radius_);
    ar << make_nvp("parent_sample", v.parent_sample_);
}

template<typename Archive>
void load(Archive& ar,
    dogen::swc::point& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("sample_number", v.sample_number_);
    ar >> make_nvp("unparsed_structure_identifier", v.unparsed_structure_identifier_);
    ar >> make_nvp("structure_identifier", v.structure_identifier_);
    ar >> make_nvp("x", v.x_);
    ar >> make_nvp("y", v.y_);
    ar >> make_nvp("z", v.z_);
    ar >> make_nvp("radius", v.radius_);
    ar >> make_nvp("parent_sample", v.parent_sample_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const dogen::swc::point& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, dogen::swc::point& v, unsigned int version);

template void save(archive::text_oarchive& ar, const dogen::swc::point& v, unsigned int version);
template void load(archive::text_iarchive& ar, dogen::swc::point& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const dogen::swc::point& v, unsigned int version);
template void load(archive::binary_iarchive& ar, dogen::swc::point& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const dogen::swc::point& v, unsigned int version);
template void load(archive::xml_iarchive& ar, dogen::swc::point& v, unsigned int version);

} }
