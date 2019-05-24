//
//  TokenState.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/22/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef TokenState_hpp
#define TokenState_hpp

#include "Compiler.hpp"
#include "ParseData.hpp"
#include "Operators.hpp"
#include <stdio.h>
#include <string>

#endif /* TokenState_hpp */

template <char token>
ParseData tokenize(std::string const& text, ParsingLog& parse, Scope& scope, TypeMap const& types) = delete;

template<>
ParseData tokenize<' '>(std::string const& text, ParsingLog& parse, Scope& scope, TypeMap const& types);

template<>
ParseData tokenize<'+'>(std::string const& text, ParsingLog& parse, Scope& scope, TypeMap const& types);
