//
//  Variable.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

#include "Types.hpp"
#include "Scope.hpp"

#include <string>

class Variable {
public:
    Variable();
    virtual std::string get_tibasic(Scope* scope);
};

class NumVariable : Variable {
    int index;
public:
    NumVariable(int index_);
    virtual std::string get_tibasic(Scope* scope);
};

class StrVariable : Variable {
    NumVariable offset, length;
public:
    StrVariable(int offset_idx, int length_idx);
    virtual std::string get_tibasic(Scope* scope);
};

#endif /* Variable_hpp */
