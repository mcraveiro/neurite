#include "dogen/swc/types/header.hpp"

namespace dogen {
namespace swc {

header::header()
    : soma_area_(static_cast<double>(0)),
      shrinkage_correction_(static_cast<double>(0)) { }

header::header(
    const std::string& original_source,
    const std::string& creature,
    const std::string& region,
    const std::string& field_or_layer,
    const std::string& type,
    const std::string& contributor,
    const std::string& reference,
    const std::string& raw,
    const std::string& extras,
    const double soma_area,
    const double shrinkage_correction,
    const std::string& version_number,
    const std::string& version_date,
    const std::string& scale)
    : original_source_(original_source),
      creature_(creature),
      region_(region),
      field_or_layer_(field_or_layer),
      type_(type),
      contributor_(contributor),
      reference_(reference),
      raw_(raw),
      extras_(extras),
      soma_area_(soma_area),
      shrinkage_correction_(shrinkage_correction),
      version_number_(version_number),
      version_date_(version_date),
      scale_(scale) { }

void header::swap(header& other) noexcept {
    using std::swap;
    swap(original_source_, other.original_source_);
    swap(creature_, other.creature_);
    swap(region_, other.region_);
    swap(field_or_layer_, other.field_or_layer_);
    swap(type_, other.type_);
    swap(contributor_, other.contributor_);
    swap(reference_, other.reference_);
    swap(raw_, other.raw_);
    swap(extras_, other.extras_);
    swap(soma_area_, other.soma_area_);
    swap(shrinkage_correction_, other.shrinkage_correction_);
    swap(version_number_, other.version_number_);
    swap(version_date_, other.version_date_);
    swap(scale_, other.scale_);
}

bool header::operator==(const header& rhs) const {
    return original_source_ == rhs.original_source_ &&
        creature_ == rhs.creature_ &&
        region_ == rhs.region_ &&
        field_or_layer_ == rhs.field_or_layer_ &&
        type_ == rhs.type_ &&
        contributor_ == rhs.contributor_ &&
        reference_ == rhs.reference_ &&
        raw_ == rhs.raw_ &&
        extras_ == rhs.extras_ &&
        soma_area_ == rhs.soma_area_ &&
        shrinkage_correction_ == rhs.shrinkage_correction_ &&
        version_number_ == rhs.version_number_ &&
        version_date_ == rhs.version_date_ &&
        scale_ == rhs.scale_;
}

header& header::operator=(header other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::string& header::original_source() const {
    return original_source_;
}

std::string& header::original_source() {
    return original_source_;
}

void header::original_source(const std::string& v) {
    original_source_ = v;
}

void header::original_source(const std::string&& v) {
    original_source_ = std::move(v);
}

const std::string& header::creature() const {
    return creature_;
}

std::string& header::creature() {
    return creature_;
}

void header::creature(const std::string& v) {
    creature_ = v;
}

void header::creature(const std::string&& v) {
    creature_ = std::move(v);
}

const std::string& header::region() const {
    return region_;
}

std::string& header::region() {
    return region_;
}

void header::region(const std::string& v) {
    region_ = v;
}

void header::region(const std::string&& v) {
    region_ = std::move(v);
}

const std::string& header::field_or_layer() const {
    return field_or_layer_;
}

std::string& header::field_or_layer() {
    return field_or_layer_;
}

void header::field_or_layer(const std::string& v) {
    field_or_layer_ = v;
}

void header::field_or_layer(const std::string&& v) {
    field_or_layer_ = std::move(v);
}

const std::string& header::type() const {
    return type_;
}

std::string& header::type() {
    return type_;
}

void header::type(const std::string& v) {
    type_ = v;
}

void header::type(const std::string&& v) {
    type_ = std::move(v);
}

const std::string& header::contributor() const {
    return contributor_;
}

std::string& header::contributor() {
    return contributor_;
}

void header::contributor(const std::string& v) {
    contributor_ = v;
}

void header::contributor(const std::string&& v) {
    contributor_ = std::move(v);
}

const std::string& header::reference() const {
    return reference_;
}

std::string& header::reference() {
    return reference_;
}

void header::reference(const std::string& v) {
    reference_ = v;
}

void header::reference(const std::string&& v) {
    reference_ = std::move(v);
}

const std::string& header::raw() const {
    return raw_;
}

std::string& header::raw() {
    return raw_;
}

void header::raw(const std::string& v) {
    raw_ = v;
}

void header::raw(const std::string&& v) {
    raw_ = std::move(v);
}

const std::string& header::extras() const {
    return extras_;
}

std::string& header::extras() {
    return extras_;
}

void header::extras(const std::string& v) {
    extras_ = v;
}

void header::extras(const std::string&& v) {
    extras_ = std::move(v);
}

double header::soma_area() const {
    return soma_area_;
}

void header::soma_area(const double v) {
    soma_area_ = v;
}

double header::shrinkage_correction() const {
    return shrinkage_correction_;
}

void header::shrinkage_correction(const double v) {
    shrinkage_correction_ = v;
}

const std::string& header::version_number() const {
    return version_number_;
}

std::string& header::version_number() {
    return version_number_;
}

void header::version_number(const std::string& v) {
    version_number_ = v;
}

void header::version_number(const std::string&& v) {
    version_number_ = std::move(v);
}

const std::string& header::version_date() const {
    return version_date_;
}

std::string& header::version_date() {
    return version_date_;
}

void header::version_date(const std::string& v) {
    version_date_ = v;
}

void header::version_date(const std::string&& v) {
    version_date_ = std::move(v);
}

const std::string& header::scale() const {
    return scale_;
}

std::string& header::scale() {
    return scale_;
}

void header::scale(const std::string& v) {
    scale_ = v;
}

void header::scale(const std::string&& v) {
    scale_ = std::move(v);
}

} }
