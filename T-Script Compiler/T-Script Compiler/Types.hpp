//
//  Types.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

#include "Scope.hpp"
#include "Variable.hpp"

#include <unordered_map>
#include <string>

class Type {
public:
    virtual std::string get_type_tibasic(Scope* scope);
    virtual Variable create_var(Scope* scope);
    Type();
};

class Num : public Type {
public:
    virtual std::string get_type_tibasic(int index, Scope* scope);
    virtual Variable create_var(Scope* scope);
    Num();
};

class Str : public Type {
public:
    virtual std::string get_type_tibasic(NumVariable const& start_offset, NumVariable const& length, Scope* scope);
    virtual Variable create_var(Scope* scope);
    Str();
};

class Func : public Type {
public:
    virtual std::string get_type_tibasic(int index, Scope* scope);
    virtual Variable create_var(Scope* scope);
    Func();
};

class TypeMap {
    std::unordered_map<std::string, Type> user_defined;
    static std::unordered_map<std::string, Type> primitive;
public:
    bool contains(std::string const& type_name) const;
    Type const* get(std::string const& type_name) const;
};
#endif /* Types_hpp */
