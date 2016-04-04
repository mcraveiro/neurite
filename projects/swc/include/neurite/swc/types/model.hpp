/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2015-2016 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#ifndef NEURITE_SWC_TYPES_MODEL_HPP
#define NEURITE_SWC_TYPES_MODEL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <algorithm>
#include <boost/optional.hpp>
#include "neurite/swc/types/header.hpp"
#include "neurite/swc/types/sample.hpp"
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
        const std::list<neurite::swc::sample>& samples);

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
     * @brief All samples that are part of this file.
     */
    /**@{*/
    const std::list<neurite::swc::sample>& samples() const;
    std::list<neurite::swc::sample>& samples();
    void samples(const std::list<neurite::swc::sample>& v);
    void samples(const std::list<neurite::swc::sample>&& v);
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
    std::list<neurite::swc::sample> samples_;
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
