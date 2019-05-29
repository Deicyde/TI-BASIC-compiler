//
//  ParseData.cpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#include "ParseData.hpp"

#include "Keywords.hpp"

void OpenComment::preform_on(NewLine& front, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.pop_front();
    out.push_front(CloseComment(text));
}

void OpenComment::preform_on(ParseData& front, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.pop_front();
    text.append(front.to_string());
    out.push_front(*this);
}

std::string CloseComment::to_tibasic() {
    text->insert(0, ";");
    return *text;
}

void WrittenString::preform_on(ParseData& front, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
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

void InvokeType::preform_on(WrittenString& front, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.pop_front();
    Variable new_var(type);
    scope.add_var(front.text, new_var);
    out.push_front(CreateVar(type));
}

void SlashOperand::preform_on(SlashOperand& front, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {
    out.pop_front();
    out.push_front(OpenComment());
}














