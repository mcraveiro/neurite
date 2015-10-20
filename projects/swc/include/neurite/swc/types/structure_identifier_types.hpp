#ifndef NEURITE_SWC_TYPES_STRUCTURE_IDENTIFIER_TYPES_HPP
#define NEURITE_SWC_TYPES_STRUCTURE_IDENTIFIER_TYPES_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace neurite {
namespace swc {

/**
 * @brief Structure Identifier as per SWC spec and conventions.
 */
enum class structure_identifier_types : unsigned int {
    invalid = 0, ///< Represents an uninitialised enum
    soma = 1,
    axon = 2,
    basal_dendrite = 3,
    apical_dendrite = 4,
    fork_point = 5,
    end_point = 6,
    custom = 7
};

} }

#endif
