//
//  ParseData.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "ParseData.hpp"

#include "Keywords.hpp"

void ParseData::preform_on(WhiteSpace& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.push_front(*this);
}

void ParseData::preform_on(WrittenString& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    next.preform_on(out.front(), out, err_out, types, scope);
    out.push_front(*this);
}

void OpenComment::preform_on(NewLine& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.push_front(CloseComment(text));
}

void OpenComment::preform_on(ParseData& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    text.append(next.to_string());
    out.push_front(*this);
}

std::string CloseComment::to_tibasic() {
    text->insert(0, ";");
    return *text;
}

void WrittenString::preform_on(ParseData& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    ParseData pd = SyntaxError();
    if(Keyword::key_exists(text)) {
        pd = Keyword::get_keyword(text);
    }
    else if(types.contains(text)) {
        pd = InvokeType(types.get(text));
    }
    else if(scope->has_var(text)) {
        pd = InvokeVariable(scope->get_var(text));
    }
    out.push_front(pd);
}

void InvokeType::preform_on(WrittenString& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    Variable new_var = scope->create_local(type);
    scope->add_var(next.text, new_var);
    out.push_front(CreateVariable(type));
}

void SlashOperand::preform_on(SlashOperand& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.push_front(OpenComment());
}














