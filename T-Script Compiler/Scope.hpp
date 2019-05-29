//
//  Scope.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/22/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Scope_hpp
#define Scope_hpp

#include "Variable.hpp"

#include <string>
#include <unordered_map>

using VarMap = std::unordered_map<std::string, Variable>;

class Scope {
    Scope * larger;
    VarMap variables;
public:
    Scope();
    Scope(Scope* last);
    ~Scope();
    
    bool has_var(std::string const& var_name) const;
    Variable* get_var(std::string const& var_name);
    void add_var(std::string const& var_name, Variable var);
};


#endif /* Scope_hpp */
