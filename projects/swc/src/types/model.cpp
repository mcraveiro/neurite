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
#include "neurite/swc/types/model.hpp"

namespace neurite {
namespace swc {

model::model(model&& rhs)
    : header_(std::move(rhs.header_)),
      samples_(std::move(rhs.samples_)) { }

model::model(
    const boost::optional<neurite::swc::header>& header,
    const std::list<neurite::swc::sample>& samples)
    : header_(header),
      samples_(samples) { }

void model::swap(model& other) noexcept {
    using std::swap;
    swap(header_, other.header_);
    swap(samples_, other.samples_);
}

bool model::operator==(const model& rhs) const {
    return header_ == rhs.header_ &&
        samples_ == rhs.samples_;
}

model& model::operator=(model other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const boost::optional<neurite::swc::header>& model::header() const {
    return header_;
}

boost::optional<neurite::swc::header>& model::header() {
    return header_;
}

void model::header(const boost::optional<neurite::swc::header>& v) {
    header_ = v;
}

void model::header(const boost::optional<neurite::swc::header>&& v) {
    header_ = std::move(v);
}

const std::list<neurite::swc::sample>& model::samples() const {
    return samples_;
}

std::list<neurite::swc::sample>& model::samples() {
    return samples_;
}

void model::samples(const std::list<neurite::swc::sample>& v) {
    samples_ = v;
}

void model::samples(const std::list<neurite::swc::sample>&& v) {
    samples_ = std::move(v);
}

} }
