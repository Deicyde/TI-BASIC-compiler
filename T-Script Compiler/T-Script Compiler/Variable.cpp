//
//  Variable.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Variable.hpp"

NumVariable::NumVariable(int index_) : index(index_) { }

std::string NumVariable::get_tibasic(Scope* scope) {
    return Num::get_type_tibasic(index, scope);
}

StrVariable::StrVariable(int offset_idx, int length_idx) : offset(offset_idx), length(length_idx) { }

std::string StrVariable::get_tibasic(Scope* scope) {
    return Str::get_type_tibasic(offset, length, scope);
}
