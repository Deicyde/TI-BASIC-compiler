//
//  ParseData.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "ParseData.hpp"

InvokeType::InvokeType(Type const* type_) : type(type_) {}
InvokeVariable::InvokeVariable(Variable * var_) : var(var_) {}
UseOperator::UseOperator(Operator const* op) : operand(op) {}
