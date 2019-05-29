//
//  Scope.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/22/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Scope.hpp"

Scope::Scope() : larger(nullptr) {}
Scope::Scope(Scope* last) : larger(last) {}

Scope::~Scope() {
    delete larger;
}

bool Scope::has_var(std::string const& var_name) const {
    for(Scope const* current = this; current != nullptr; current = current->larger) {
        if(current->variables.count(var_name)) return true;
    }
    return false;
}

void Scope::add_var(std::string const& var_name, Variable var) {
    variables[var_name] = var;
}

Variable* Scope::get_var(std::string const& var_name) {
    return &variables[var_name];
}
