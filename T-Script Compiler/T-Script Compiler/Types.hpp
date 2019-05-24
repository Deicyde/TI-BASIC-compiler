//
//  Types.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>

class Type {
    int size;
public:
    Type() : size(1) {}
};

class TypeMap {
    std::unordered_map<std::string, Type> user_defined;
    static std::unordered_map<std::string, Type> primitive;
public:
    bool contains(std::string const& type_name) const;
    
    Type const* get(std::string const& type_name) const;
};
#endif /* Types_hpp */
