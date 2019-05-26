//
//  TokenState.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/22/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "TokenState.hpp"

template<>
void tokenize<' '>(std::string const& text, ParsingLog& parse, Scope& scope, TypeMap const& types) {
    
    bool has_back = parse.size() > 0;
    ParseData pd;
    
    if(types.contains(text)) pd = InvokeType(types.get(text));
    else if(scope.has_var(text)) pd = InvokeVariable(scope.get_var(text));
    else if(operators.count(text)) pd = UseOperator(&operators.at(text));
    
    if(has_back) {
        parse.push_back(parse.back().preform_on(pd));
    }
    parse.push_back(pd);
}

template<>
void tokenize<'+'>(std::string const& text, ParsingLog& parse, Scope& scope, TypeMap const& types) {
    bool has_back = parse.size() > 0;
    if(text.length() > 0) {
        ParseData pd;
        if(scope.has_var(text)) pd = InvokeVariable(scope.get_var(text));
        else; //pd = Error (TODO:)
        parse.push_back(pd);
    }
    
    return P
}
template<>
void tokenize<'-'>(std::string const& text, ParsingLog& parse, Scope& scope, TypeMap const& types) {
    bool has_back = parse.size() > 0;
    if(text.length() > 0) {
        ParseData pd;
        if(scope.has_var(text)) pd = InvokeVariable(scope.get_var(text));
        else; //pd = Error (TODO:)
        parse.push_back(pd);
    }
    
    return P
}

