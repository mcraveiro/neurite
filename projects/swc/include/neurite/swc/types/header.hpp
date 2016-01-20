#ifndef NEURITE_SWC_TYPES_HEADER_HPP
#define NEURITE_SWC_TYPES_HEADER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include "neurite/swc/serialization/header_fwd_ser.hpp"

namespace neurite {
namespace swc {

class header final {
public:
    header(const header&) = default;
    header(header&&) = default;
    ~header() = default;

public:
    header();

public:
    header(
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
        const std::string& scale);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const header& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, header& v, unsigned int version);

public:
    /**
     * @brief File type delivered by digitisation equipment.
     */
    /**@{*/
    const std::string& original_source() const;
    std::string& original_source();
    void original_source(const std::string& v);
    void original_source(const std::string&& v);
    /**@}*/

    /**
     * @brief Species from which the cell came
     */
    /**@{*/
    const std::string& creature() const;
    std::string& creature();
    void creature(const std::string& v);
    void creature(const std::string&& v);
    /**@}*/

    /**
     * @brief Brain region.
     */
    /**@{*/
    const std::string& region() const;
    std::string& region();
    void region(const std::string& v);
    void region(const std::string&& v);
    /**@}*/

    /**
     * @brief Location within region
     */
    /**@{*/
    const std::string& field_or_layer() const;
    std::string& field_or_layer();
    void field_or_layer(const std::string& v);
    void field_or_layer(const std::string&& v);
    /**@}*/

    /**
     * @brief Cell type
     */
    /**@{*/
    const std::string& type() const;
    std::string& type();
    void type(const std::string& v);
    void type(const std::string&& v);
    /**@}*/

    /**
     * @brief Name – initials, organisation, e.g. Turner – DA, Duke
     */
    /**@{*/
    const std::string& contributor() const;
    std::string& contributor();
    void contributor(const std::string& v);
    void contributor(const std::string&& v);
    /**@}*/

    const std::string& reference() const;
    std::string& reference();
    void reference(const std::string& v);
    void reference(const std::string&& v);

    /**
     * @brief Where the data has been published
     */
    /**@{*/
    const std::string& raw() const;
    std::string& raw();
    void raw(const std::string& v);
    void raw(const std::string&& v);
    /**@}*/

    /**
     * @brief Files containing further information on this cell.
     */
    /**@{*/
    const std::string& extras() const;
    std::string& extras();
    void extras(const std::string& v);
    void extras(const std::string&& v);
    /**@}*/

    /**
     * @brief Area of soma (in um2).
     */
    /**@{*/
    double soma_area() const;
    void soma_area(const double v);
    /**@}*/

    /**
     * @brief x, y and z correction factors
     */
    /**@{*/
    double shrinkage_correction() const;
    void shrinkage_correction(const double v);
    /**@}*/

    /**
     * @brief To identify different versions of the same raw data.
     */
    /**@{*/
    const std::string& version_number() const;
    std::string& version_number();
    void version_number(const std::string& v);
    void version_number(const std::string&& v);
    /**@}*/

    /**
     * @brief Date this version was created (yyyy – mm – dd).
     */
    /**@{*/
    const std::string& version_date() const;
    std::string& version_date();
    void version_date(const std::string& v);
    void version_date(const std::string&& v);
    /**@}*/

    /**
     * @brief Used internally to record applied shrinkage corrections.
     */
    /**@{*/
    const std::string& scale() const;
    std::string& scale();
    void scale(const std::string& v);
    void scale(const std::string&& v);
    /**@}*/

public:
    bool operator==(const header& rhs) const;
    bool operator!=(const header& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(header& other) noexcept;
    header& operator=(header other);

private:
    std::string original_source_;
    std::string creature_;
    std::string region_;
    std::string field_or_layer_;
    std::string type_;
    std::string contributor_;
    std::string reference_;
    std::string raw_;
    std::string extras_;
    double soma_area_;
    double shrinkage_correction_;
    std::string version_number_;
    std::string version_date_;
    std::string scale_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::swc::header& lhs,
    neurite::swc::header& rhs) {
    lhs.swap(rhs);
}

}

#endif
