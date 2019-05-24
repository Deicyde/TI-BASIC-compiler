//
//  Compiler.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/20/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Compiler_hpp
#define Compiler_hpp

#include "Error.hpp"

#include <stdio.h>
#include <set>
#include <vector>
#include <fstream>

class Compiler {
    std::ifstream input;
    std::ofstream output;
    std::set<char> tokens;
public:
    Compiler(std::string file_in, std::string file_out);
    ErrorList compile();
private:
    ErrorList& parse_line(std::string const& line);
    char read_until_tok(std::string const& line, std::string& read_in);
};


#endif /* Compiler_hpp */
