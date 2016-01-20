#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

namespace neurite {
namespace swc {

template<typename Archive>
void register_types(Archive&) {
}

template void register_types(boost::archive::polymorphic_oarchive&);
template void register_types(boost::archive::polymorphic_iarchive&);

template void register_types(boost::archive::text_oarchive&);
template void register_types(boost::archive::text_iarchive&);

template void register_types(boost::archive::binary_oarchive&);
template void register_types(boost::archive::binary_iarchive&);

template void register_types(boost::archive::xml_oarchive&);
template void register_types(boost::archive::xml_iarchive&);

} }
