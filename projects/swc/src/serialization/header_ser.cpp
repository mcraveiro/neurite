#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "neurite/swc/serialization/header_ser.hpp"

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const neurite::swc::header& v,
    const unsigned int /*version*/) {
    ar << make_nvp("original_source", v.original_source_);
    ar << make_nvp("creature", v.creature_);
    ar << make_nvp("region", v.region_);
    ar << make_nvp("field_or_layer", v.field_or_layer_);
    ar << make_nvp("type", v.type_);
    ar << make_nvp("contributor", v.contributor_);
    ar << make_nvp("reference", v.reference_);
    ar << make_nvp("raw", v.raw_);
    ar << make_nvp("extras", v.extras_);
    ar << make_nvp("soma_area", v.soma_area_);
    ar << make_nvp("shrinkage_correction", v.shrinkage_correction_);
    ar << make_nvp("version_number", v.version_number_);
    ar << make_nvp("version_date", v.version_date_);
    ar << make_nvp("scale", v.scale_);
}

template<typename Archive>
void load(Archive& ar,
    neurite::swc::header& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("original_source", v.original_source_);
    ar >> make_nvp("creature", v.creature_);
    ar >> make_nvp("region", v.region_);
    ar >> make_nvp("field_or_layer", v.field_or_layer_);
    ar >> make_nvp("type", v.type_);
    ar >> make_nvp("contributor", v.contributor_);
    ar >> make_nvp("reference", v.reference_);
    ar >> make_nvp("raw", v.raw_);
    ar >> make_nvp("extras", v.extras_);
    ar >> make_nvp("soma_area", v.soma_area_);
    ar >> make_nvp("shrinkage_correction", v.shrinkage_correction_);
    ar >> make_nvp("version_number", v.version_number_);
    ar >> make_nvp("version_date", v.version_date_);
    ar >> make_nvp("scale", v.scale_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const neurite::swc::header& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, neurite::swc::header& v, unsigned int version);

template void save(archive::text_oarchive& ar, const neurite::swc::header& v, unsigned int version);
template void load(archive::text_iarchive& ar, neurite::swc::header& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const neurite::swc::header& v, unsigned int version);
template void load(archive::binary_iarchive& ar, neurite::swc::header& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const neurite::swc::header& v, unsigned int version);
template void load(archive::xml_iarchive& ar, neurite::swc::header& v, unsigned int version);

} }
