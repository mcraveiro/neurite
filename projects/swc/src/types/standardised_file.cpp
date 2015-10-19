#include "dogen/swc/types/standardised_file.hpp"

namespace dogen {
namespace swc {

standardised_file::standardised_file(standardised_file&& rhs)
    : header_(std::move(rhs.header_)),
      points_(std::move(rhs.points_)) { }

standardised_file::standardised_file(
    const boost::optional<dogen::swc::header>& header,
    const std::list<dogen::swc::point>& points)
    : header_(header),
      points_(points) { }

void standardised_file::swap(standardised_file& other) noexcept {
    using std::swap;
    swap(header_, other.header_);
    swap(points_, other.points_);
}

bool standardised_file::operator==(const standardised_file& rhs) const {
    return header_ == rhs.header_ &&
        points_ == rhs.points_;
}

standardised_file& standardised_file::operator=(standardised_file other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const boost::optional<dogen::swc::header>& standardised_file::header() const {
    return header_;
}

boost::optional<dogen::swc::header>& standardised_file::header() {
    return header_;
}

void standardised_file::header(const boost::optional<dogen::swc::header>& v) {
    header_ = v;
}

void standardised_file::header(const boost::optional<dogen::swc::header>&& v) {
    header_ = std::move(v);
}

const std::list<dogen::swc::point>& standardised_file::points() const {
    return points_;
}

std::list<dogen::swc::point>& standardised_file::points() {
    return points_;
}

void standardised_file::points(const std::list<dogen::swc::point>& v) {
    points_ = v;
}

void standardised_file::points(const std::list<dogen::swc::point>&& v) {
    points_ = std::move(v);
}

} }
