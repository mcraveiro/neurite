#ifndef NEURITE_SWC_TYPES_MODEL_HPP
#define NEURITE_SWC_TYPES_MODEL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <algorithm>
#include <boost/optional.hpp>
#include "neurite/swc/types/point.hpp"
#include "neurite/swc/types/header.hpp"
#include "neurite/swc/serialization/model_fwd_ser.hpp"

namespace neurite {
namespace swc {

/**
 * @brief Represents a standardised SWC file.
 */
class model final {
public:
    model() = default;
    model(const model&) = default;
    ~model() = default;

public:
    model(model&& rhs);

public:
    model(
        const boost::optional<neurite::swc::header>& header,
        const std::list<neurite::swc::point>& points);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const model& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, model& v, unsigned int version);

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
    bool operator==(const model& rhs) const;
    bool operator!=(const model& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(model& other) noexcept;
    model& operator=(model other);

private:
    boost::optional<neurite::swc::header> header_;
    std::list<neurite::swc::point> points_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::swc::model& lhs,
    neurite::swc::model& rhs) {
    lhs.swap(rhs);
}

}

#endif
