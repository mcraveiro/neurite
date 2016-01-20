#ifndef NEURITE_SWC_TYPES_HYDRATION_ERROR_HPP
#define NEURITE_SWC_TYPES_HYDRATION_ERROR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <boost/exception/info.hpp>

namespace neurite {
namespace swc {

class hydration_error : public virtual std::exception, public virtual boost::exception {
public:
    hydration_error() = default;
    ~hydration_error() noexcept = default;

public:
    hydration_error(const std::string& message) : message_(message) { }

public:
    const char* what() const noexcept { return(message_.c_str()); }

private:
    const std::string message_;
};

} }

#endif
