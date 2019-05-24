//
//  ParseData.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef ParseData_hpp
#define ParseData_hpp

#include "Scope.hpp"
#include "Scope.hpp"
#include "Error.hpp"
#include "Types.hpp"
#include "Variable.hpp"
#include "Operators.hpp"

#include <stdio.h>
#include <string>
#include <vector>
#include <set>

class ParseData {
public:
    virtual ParseData preform_on(ParseData other);
};
using ParsingLog = std::vector<ParseData>;

class InvokeType : public ParseData {
    Type const* type;
public:
    InvokeType(Type const* type_);
    ParseData preform_on(InvokeType other);
};

class InvokeVariable : public ParseData {
    Variable * var;
public:
    InvokeVariable(Variable * var_);
    ParseData preform_on(InvokeType other);
};

class UseOperator : public ParseData {
    Operator const* operand;
public:
    UseOperator(Operator const* op);
    ParseData preform_on(InvokeVariable other);
};

class PlusOperator : public UseOperator {
    Variable * operating;
public:
    PlusOperator(Variable * operating);
};

#endif /* ParseData_hpp */
