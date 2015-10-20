#ifndef NEURITE_SWC_TYPES_STANDARDISED_FILE_HPP
#define NEURITE_SWC_TYPES_STANDARDISED_FILE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <algorithm>
#include <boost/optional.hpp>
#include "neurite/swc/types/point.hpp"
#include "neurite/swc/types/header.hpp"
#include "neurite/swc/serialization/standardised_file_fwd_ser.hpp"

namespace neurite {
namespace swc {

/**
 * @brief Represents a standardised SWC file.
 */
class standardised_file final {
public:
    standardised_file() = default;
    standardised_file(const standardised_file&) = default;
    ~standardised_file() = default;

public:
    standardised_file(standardised_file&& rhs);

public:
    standardised_file(
        const boost::optional<neurite::swc::header>& header,
        const std::list<neurite::swc::point>& points);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const standardised_file& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, standardised_file& v, unsigned int version);

public:
    const boost::optional<neurite::swc::header>& header() const;
    boost::optional<neurite::swc::header>& header();
    void header(const boost::optional<neurite::swc::header>& v);
    void header(const boost::optional<neurite::swc::header>&& v);

    /**
     * @brief All points that are part of this file.
     */
    /**@{*/
    const std::list<neurite::swc::point>& points() const;
    std::list<neurite::swc::point>& points();
    void points(const std::list<neurite::swc::point>& v);
    void points(const std::list<neurite::swc::point>&& v);
    /**@}*/

public:
    bool operator==(const standardised_file& rhs) const;
    bool operator!=(const standardised_file& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(standardised_file& other) noexcept;
    standardised_file& operator=(standardised_file other);

private:
    boost::optional<neurite::swc::header> header_;
    std::list<neurite::swc::point> points_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::swc::standardised_file& lhs,
    neurite::swc::standardised_file& rhs) {
    lhs.swap(rhs);
}

}

#endif
