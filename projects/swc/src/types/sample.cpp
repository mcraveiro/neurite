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
#include "neurite/swc/types/sample.hpp"

namespace neurite {
namespace swc {

sample::sample()
    : number_(static_cast<unsigned int>(0)),
      unparsed_structure_identifier_(static_cast<int>(0)),
      structure_identifier_(static_cast<neurite::swc::structure_identifier_types>(0)),
      radius_(static_cast<double>(0)),
      parent_(static_cast<int>(0)),
      line_number_(static_cast<unsigned int>(0)) { }

sample::sample(
    const unsigned int number,
    const int unparsed_structure_identifier,
    const neurite::swc::structure_identifier_types structure_identifier,
    const neurite::swc::point& position,
    const double radius,
    const int parent,
    const unsigned int line_number)
    : number_(number),
      unparsed_structure_identifier_(unparsed_structure_identifier),
      structure_identifier_(structure_identifier),
      position_(position),
      radius_(radius),
      parent_(parent),
      line_number_(line_number) { }

void sample::swap(sample& other) noexcept {
    using std::swap;
    swap(number_, other.number_);
    swap(unparsed_structure_identifier_, other.unparsed_structure_identifier_);
    swap(structure_identifier_, other.structure_identifier_);
    swap(position_, other.position_);
    swap(radius_, other.radius_);
    swap(parent_, other.parent_);
    swap(line_number_, other.line_number_);
}

bool sample::operator==(const sample& rhs) const {
    return number_ == rhs.number_ &&
        unparsed_structure_identifier_ == rhs.unparsed_structure_identifier_ &&
        structure_identifier_ == rhs.structure_identifier_ &&
        position_ == rhs.position_ &&
        radius_ == rhs.radius_ &&
        parent_ == rhs.parent_ &&
        line_number_ == rhs.line_number_;
}

sample& sample::operator=(sample other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

unsigned int sample::number() const {
    return number_;
}

void sample::number(const unsigned int v) {
    number_ = v;
}

int sample::unparsed_structure_identifier() const {
    return unparsed_structure_identifier_;
}

void sample::unparsed_structure_identifier(const int v) {
    unparsed_structure_identifier_ = v;
}

neurite::swc::structure_identifier_types sample::structure_identifier() const {
    return structure_identifier_;
}

void sample::structure_identifier(const neurite::swc::structure_identifier_types v) {
    structure_identifier_ = v;
}

const neurite::swc::point& sample::position() const {
    return position_;
}

neurite::swc::point& sample::position() {
    return position_;
}

void sample::position(const neurite::swc::point& v) {
    position_ = v;
}

void sample::position(const neurite::swc::point&& v) {
    position_ = std::move(v);
}

double sample::radius() const {
    return radius_;
}

void sample::radius(const double v) {
    radius_ = v;
}

int sample::parent() const {
    return parent_;
}

void sample::parent(const int v) {
    parent_ = v;
}

unsigned int sample::line_number() const {
    return line_number_;
}

void sample::line_number(const unsigned int v) {
    line_number_ = v;
}

} }
