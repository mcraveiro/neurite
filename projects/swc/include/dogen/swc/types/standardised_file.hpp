#ifndef DOGEN_SWC_TYPES_STANDARDISED_FILE_HPP
#define DOGEN_SWC_TYPES_STANDARDISED_FILE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <algorithm>
#include <boost/optional.hpp>
#include "dogen/swc/types/point.hpp"
#include "dogen/swc/types/header.hpp"
#include "dogen/swc/serialization/standardised_file_fwd_ser.hpp"

namespace dogen {
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
        const boost::optional<dogen::swc::header>& header,
        const std::list<dogen::swc::point>& points);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const standardised_file& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, standardised_file& v, unsigned int version);

public:
    const boost::optional<dogen::swc::header>& header() const;
    boost::optional<dogen::swc::header>& header();
    void header(const boost::optional<dogen::swc::header>& v);
    void header(const boost::optional<dogen::swc::header>&& v);

    /**
     * @brief All points that are part of this file.
     */
    /**@{*/
    const std::list<dogen::swc::point>& points() const;
    std::list<dogen::swc::point>& points();
    void points(const std::list<dogen::swc::point>& v);
    void points(const std::list<dogen::swc::point>&& v);
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
    boost::optional<dogen::swc::header> header_;
    std::list<dogen::swc::point> points_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::swc::standardised_file& lhs,
    dogen::swc::standardised_file& rhs) {
    lhs.swap(rhs);
}

}

#endif
