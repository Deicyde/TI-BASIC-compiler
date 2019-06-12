//
//  Compiler.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/20/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//


#ifndef Compiler_hpp
#define Compiler_hpp

#include "ParseData.hpp"
#include "Error.hpp"

#include <fstream>
#include <string>
#include <unordered_map>

class TokenMap;

class Compiler {
    std::ifstream input;
    std::ofstream output;
    static const TokenMap token_map;
public:
    Compiler(std::string const& file_in, std::string const& file_out);
    ~Compiler();
    ErrorList compile();
private:
    void parse_line(std::string const& line, std::string& read, ParsingLog& out);
    char read_until_tok(std::string const& line, std::string& read_in);
    std::string const& write_from_parse(ParsingLog& pl);
};

class TokenMap {
    static const std::unordered_map<char, ParseData> tokens;
public:
    ParseData get_token(char tok) const;
    bool has_token(char tok) const;
};


#endif /* Compiler_hpp */
