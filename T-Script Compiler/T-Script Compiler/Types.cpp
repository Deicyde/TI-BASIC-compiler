//
//  Types.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Types.hpp"

std::unordered_map<std::string, Type> TypeMap::primitive = {
    {"num"   , Num()  },
    {"string", Str()  },
    {"func"  , Func() }
};

std::string Num::get_type_tibasic(int index, Scope* scope) {
    std::string ret;
    ret += scope->list_name();
    ret += "(";
    ret += index;
    ret += ")";
    return ret;
}

std::string Str::get_type_tibasic(NumVariable const& start_offset, NumVariable const& length, Scope* scope) {
    std::string ret("substr(");
    ret += scope->string_name();
    ret += ",";
    ret += start_offset.get_tibasic(scope);
    ret += ",";
    ret += length.get_tibasic(scope);
    ret += ")";
    
}

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
