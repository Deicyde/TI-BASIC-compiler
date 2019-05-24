//
//  Error.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Error_hpp
#define Error_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Error {};
using ErrorList = std::vector<Error>;

class FileError : public Error {};
class SyntaxError : public Error {};

class InvalidInputError : public FileError {};
class OutputError : public FileError {};

class RedeclarationError : public SyntaxError {
    std::string const* var_name;
public:
    RedeclarationError(std::string const& var_name_);
};

class NonexistantTypeError : public SyntaxError {
    std::string const* class_name;
public:
    NonexistantTypeError(std::string const&);
};

#endif /* Error_hpp */
