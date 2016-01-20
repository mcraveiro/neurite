#include "neurite/swc/types/point.hpp"

namespace neurite {
namespace swc {

point::point()
    : sample_number_(static_cast<unsigned int>(0)),
      unparsed_structure_identifier_(static_cast<int>(0)),
      structure_identifier_(static_cast<neurite::swc::structure_identifier_types>(0)),
      x_(static_cast<double>(0)),
      y_(static_cast<double>(0)),
      z_(static_cast<double>(0)),
      radius_(static_cast<double>(0)),
      parent_sample_(static_cast<int>(0)),
      line_number_(static_cast<unsigned int>(0)) { }

point::point(
    const unsigned int sample_number,
    const int unparsed_structure_identifier,
    const neurite::swc::structure_identifier_types structure_identifier,
    const double x,
    const double y,
    const double z,
    const double radius,
    const int parent_sample,
    const unsigned int line_number)
    : sample_number_(sample_number),
      unparsed_structure_identifier_(unparsed_structure_identifier),
      structure_identifier_(structure_identifier),
      x_(x),
      y_(y),
      z_(z),
      radius_(radius),
      parent_sample_(parent_sample),
      line_number_(line_number) { }

void point::swap(point& other) noexcept {
    using std::swap;
    swap(sample_number_, other.sample_number_);
    swap(unparsed_structure_identifier_, other.unparsed_structure_identifier_);
    swap(structure_identifier_, other.structure_identifier_);
    swap(x_, other.x_);
    swap(y_, other.y_);
    swap(z_, other.z_);
    swap(radius_, other.radius_);
    swap(parent_sample_, other.parent_sample_);
    swap(line_number_, other.line_number_);
}

bool point::operator==(const point& rhs) const {
    return sample_number_ == rhs.sample_number_ &&
        unparsed_structure_identifier_ == rhs.unparsed_structure_identifier_ &&
        structure_identifier_ == rhs.structure_identifier_ &&
        x_ == rhs.x_ &&
        y_ == rhs.y_ &&
        z_ == rhs.z_ &&
        radius_ == rhs.radius_ &&
        parent_sample_ == rhs.parent_sample_ &&
        line_number_ == rhs.line_number_;
}

point& point::operator=(point other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

unsigned int point::sample_number() const {
    return sample_number_;
}

void point::sample_number(const unsigned int v) {
    sample_number_ = v;
}

int point::unparsed_structure_identifier() const {
    return unparsed_structure_identifier_;
}

void point::unparsed_structure_identifier(const int v) {
    unparsed_structure_identifier_ = v;
}

neurite::swc::structure_identifier_types point::structure_identifier() const {
    return structure_identifier_;
}

void point::structure_identifier(const neurite::swc::structure_identifier_types v) {
    structure_identifier_ = v;
}

double point::x() const {
    return x_;
}

void point::x(const double v) {
    x_ = v;
}

double point::y() const {
    return y_;
}

void point::y(const double v) {
    y_ = v;
}

double point::z() const {
    return z_;
}

void point::z(const double v) {
    z_ = v;
}

double point::radius() const {
    return radius_;
}

void point::radius(const double v) {
    radius_ = v;
}

int point::parent_sample() const {
    return parent_sample_;
}

void point::parent_sample(const int v) {
    parent_sample_ = v;
}

unsigned int point::line_number() const {
    return line_number_;
}

void point::line_number(const unsigned int v) {
    line_number_ = v;
}

} }
