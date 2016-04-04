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
#include <sstream>
#include <boost/make_shared.hpp>
#include <boost/throw_exception.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/types/building_error.hpp"
#include "neurite/swc/types/node.hpp"
#include "neurite/swc/types/tree_factory.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("swc.tree_factory"));

const int soma_sample_number(1);
const int soma_parent_sample_number(-1);
const std::string parent_not_found("Parent for sample could not be found: ");

}

namespace neurite {
namespace swc {
/*
std::unordered_map<int, boost::shared_ptr<node>>
tree_factory::initialise_index(const model& m) const {
    std::unordered_map<int, boost::shared_ptr<node>> r;

    for (const auto& s : m.samples()) {
        auto i(r.find(s.number()));
        if (i == r.end()) {
            const auto p(std::make_pair(s.number(), boost::make_shared<node>()));
            const auto result(r.insert(p));
            i = result.first;
        }
        i->second->content(s);
    }
    return r;
}

void tree_factory::link_index(
    std::unordered_map<int, boost::shared_ptr<node>>& index) const {

    std::unordered_map<int, boost::shared_ptr<node> > r;
    for (auto& pair : index) {
        auto& node(*pair.second);
        const auto& sample(node.content());
        if (sample.number() == soma_sample_number) {
            BOOST_LOG_SEV(lg, debug) << "Found soma.";
            
            if (sample.parent() != soma_parent_sample_number) {
                BOOST_LOG_SEV(lg, warn) << "Soma has an unexpected parent: "
                                        << sample.parent()
                                        << ". Ignoring linkage.";
            }
            r.insert(pair);
            continue;
        }

        auto i(index.find(sample.parent()));
        if (i == index.end()) {
                std::stringstream s;
                s << parent_not_found << sample.number()
                  << ". Defined in line: " << sample.line_number();
                const auto msg(s.str());
                
                BOOST_LOG_SEV(lg, error) << msg;
                BOOST_THROW_EXCEPTION(building_error(msg));                
            }
            node.parent(i->second);
            i->second->children().insert(pair.second);
        }
    }
}

tree tree_factory::build(const model& m) const {
    BOOST_LOG_SEV(lg, debug) << "Building tree for model: '" << m.name() << "'";
    BOOST_LOG_SEV(lg, debug) << "Tota samples: " << m.samples().size();

    auto index(initialise_index(m));
    link_index(index);
    
    tree r;    
    return r;
}
*/
} }
