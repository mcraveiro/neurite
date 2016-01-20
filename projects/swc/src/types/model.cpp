#include "neurite/swc/types/model.hpp"

namespace neurite {
namespace swc {

model::model(model&& rhs)
    : header_(std::move(rhs.header_)),
      points_(std::move(rhs.points_)) { }

model::model(
    const boost::optional<neurite::swc::header>& header,
    const std::list<neurite::swc::point>& points)
    : header_(header),
      points_(points) { }

void model::swap(model& other) noexcept {
    using std::swap;
    swap(header_, other.header_);
    swap(points_, other.points_);
}

bool model::operator==(const model& rhs) const {
    return header_ == rhs.header_ &&
        points_ == rhs.points_;
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

const std::list<neurite::swc::point>& model::points() const {
    return points_;
}

std::list<neurite::swc::point>& model::points() {
    return points_;
}

void model::points(const std::list<neurite::swc::point>& v) {
    points_ = v;
}

void model::points(const std::list<neurite::swc::point>&& v) {
    points_ = std::move(v);
}

} }
