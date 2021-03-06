//
//  Keywords.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/28/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Keywords_hpp
#define Keywords_hpp

#include <unordered_map>
#include <string>

class Keyword : public ParseData {
    static const std::unordered_map<std::string, Keyword> words;
protected:
    KeyWord();
public:
    static bool key_exists(std::string const& key) const;
    static Keyword const& get_keyword(std::string const& key) const;
};

class IfStatement : public Keyword {
public:
    IfStatement();
}

#endif /* Keywords_hpp */
