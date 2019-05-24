//
//  Compiler.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/20/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Compiler.hpp"

Compiler::Compiler(std::string file_in, std::string file_out) : input(file_in), output(file_out) {
    static std::string token_str("\n\"'+=-*&|%^~ (){}[]<>,.?:;");
    for(int i = 0; i < token_str.length(); ++i) {
        tokens.insert(token_str[i]);
    }
}

ErrorList Compiler::compile() {
    ErrorList errors;
    if(!input.is_open()) {
        errors.push_back(InvalidInputError());
        return errors;
    }
    if(!output.is_open()) {
        errors.push_back(OutputError());
        return errors;
    }
    
    ErrorList * returned;
    for(std::string line; input.getline(line, std::numeric_limits<std::ifstream>::max(), ';'); ) {
        returned = &parse_line(line);
        errors.insert(errors.end(), returned->begin(), returned->end());
    }
    
    return errors;
}

ErrorList& Compiler::parse_line(std::string const& line) {
    std::string read;
    for(char tok = read_until_tok(line, read); tok; tok = read_until_tok(line, read)) {
        
    }
}

char Compiler::read_until_tok(std::string const& line, std::string& read_in) {
    for(int i = 0; i < line.length(); ++i) {
        if(tokens.count(line[i])) return line[i];
        read_in.push_back(line[i]);
    }
    return 0;
}















