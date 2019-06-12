//
//  Keywords.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/28/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "Keywords.hpp"

const std::unordered_map<std::string, Keyword> Keyword::words = {
    {"if", IfStatement() }
};

bool Keyword::key_exists(std::string const& key) {
    return words.count(key);
}

Keyword const& get_keyword(std::string const& key) {
    return words.at(key);
}
