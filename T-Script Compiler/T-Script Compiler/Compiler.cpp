//
//  Compiler.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/20/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Compiler.hpp"

#include "Error.hpp"
#include "Scope.hpp"

#include <vector>
#include <string>
#include <fstream>

Compiler::Compiler(std::string const& file_in, std::string const& file_out) : input(file_in), output(file_out) { }

Compiler::~Compiler() {
    input.close();
    output.close();
}

const std::unordered_map<char, ParseData> TokenMap::tokens = {
    {' ' , WhiteSpace()       },
    {'\n', NewLine()          },
    {'\t', WhiteSpace()       },
    {'+' , PlusOperand()      },
    {'"' , QuoteMark()        },
    {'\'', ApostMark()        },
    {'\\', EscapeChar()       },
    {'=' , EqualsOperand()    },
    {'-' , MinusOperand()     },
    {'*' , StarOperand()      },
    {'/' , SlashOperand()     },
    {'&' , AmpersandOperand() },
    {'|' , PipeOperand()      },
    {'%' , PercentOperand()   },
    {'^' , CarotOperand()     },
    {'~' , TildeOperand()     },
    {'(' , OpenParenthesis()  },
    {')' , CloseParenthesis() },
    {'{' , OpenCurly()        },
    {'}' , CloseCurly()       },
    {'[' , OpenSquare()       },
    {']' , CloseSquare()      },
    {'<' , LessThan()         },
    {'>' , GreaterThan()      },
    {',' , CommaOperand()     },
    {'.' , DotOperand()       },
    {'?' , QuestionMark()     },
    {':' , ColonOperand()     },
    {';' , SemiColon()        },
};

ParseData TokenMap::get_token(char tok) const {
    if(tokens.count(tok)) {
        return tokens.at(tok);
    }
    return NoTokenError(tok);
}

bool TokenMap::has_token(char tok) const {
    return tokens.count(tok);
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
    
    std::string read;
    ParsingLog parse;
    for(std::string line; std::getline(input, line); ) {
        parse_line(line, read, parse);
    }
    
    ParseData* curr, *next;
    TypeMap types;
    Scope* current_scope = new Scope();
    
    while(parse.size() > 0) {
        curr = &parse.front();
        parse.pop_front();
        if(curr->can_reduce()) {
            output << (curr->to_tibasic());
        }
        else {
            if(parse.size() > 0) {
                next = parse.front();
                parse.pop_front()
            }
            else {
                curr->preform_on(nullptr, errors, types, current_scope)
            }
            curr->preform_on(next, parse, errors, types, current_scope);
        }
    }
    delete current_scope;
    
    return errors;
}

void Compiler::parse_line(std::string const& line, std::string& read, ParsingLog& out) {
    read.clear();
    for(char tok = read_until_tok(line, read); tok; tok = read_until_tok(line, read)) {
        if(read.length() > 0) out.push_back(WrittenString::instance(read));
        out.push_back(token_map.get_token(tok));
    }
}

char Compiler::read_until_tok(std::string const& line, std::string& read_in) {
    for(int i = 0; i < line.length(); ++i) {
        if(token_map.has_token(line[i])) return line[i];
        read_in.push_back(line[i]);
    }
    return 0;
}













