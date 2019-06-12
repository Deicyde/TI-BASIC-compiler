//
//  Error.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Error_hpp
#define Error_hpp

#include "ParseData.hpp"

#include <string>
#include <list>

class Error : public ParseData {
public:
    Error();
    virtual std::string const& error_message();
};

using ErrorList = std::list<Error>;

class FileError : public Error {};

class SyntaxError : public Error {
public:
    SyntaxError() : Error() {}
};

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
    NonexistantTypeError(std::string const& class_name_);
};

class NoTokenError : public SyntaxError {
    char token;
public:
    NoTokenError(char token_) : SyntaxError(), token(token_) {}
};

#endif /* Error_hpp */
