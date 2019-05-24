//
//  Types.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Types.hpp"

bool TypeMap::contains(std::string const& type_name) const {
    return primitive.count(type_name) || user_defined.count(type_name);
}

Type const* TypeMap::get(std::string const& type_name) const {
    if(primitive.count(type_name)) {
        return &primitive.at(type_name);
    } else {
        return &user_defined.at(type_name);
    }
}

std::unordered_map<std::string, Type> TypeMap::primitive = {
    {"num",    Type()},
    {"string", Type()},
    {"func",   Type()}
};
