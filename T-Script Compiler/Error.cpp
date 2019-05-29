//
//  Error.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Error.hpp"

RedeclarationError::RedeclarationError(std::string const& var_name_) : var_name(&var_name_) {}
NonexistantTypeError::NonexistantTypeError(std::string const& class_name_) : class_name(&class_name_) {}
NoTokenError::NoTokenError(char tok) : SyntaxError(), token(tok) {}
