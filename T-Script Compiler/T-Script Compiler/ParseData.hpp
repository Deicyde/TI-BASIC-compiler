//
//  ParseData.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef ParseData_hpp
#define ParseData_hpp

#include "Error.hpp"
#include "Types.hpp"
#include "Scope.hpp"

#include <list>
#include <string>
#include <vector>

class ParseData;
class Error;
class SyntaxError;
class WhiteSpace;
class WrittenString;

using ParsingLog = std::list<ParseData>;
using ErrorList = std::list<Error>;

class ParseData {
protected:
    ParseData() {}
public:
    virtual void preform_on(ParseData& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) { }
    virtual void preform_on(WhiteSpace& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
    virtual void preform_on(WrittenString& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
    virtual bool can_reduce() { return false; }
    virtual std::string to_string() { return ""; }
    virtual std::string to_tibasic() { return ""; }
};

class WrittenString : public ParseData {
    std::string text;
public:
    WrittenString(std::string const& text_) : text(text_) { }
    static WrittenString& create_parse_obj(ParsingLog& out, ErrorList err_out, TypeMap& types, Scope* scope);
};

class WhiteSpace : public ParseData {
public:
    virtual char get_token() { return ' '; }
    WhiteSpace() : ParseData() {}
    virtual void preform_on(ParseData& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {}
};

class NewLine : public WhiteSpace {
public:
    char get_token() { return '\n'; }
    NewLine() : WhiteSpace() { }
    virtual void preform_on(ParseData& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope) {}
};

class OpenComment : public ParseData {
    std::string text;
public:
    OpenComment() : text() {}
    virtual void preform_on(NewLine& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
    virtual void preform_on(ParseData& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
    virtual std::string to_string() { return text; }
};

class CloseComment : public ParseData {
    std::string* text;
public:
    CloseComment(std::string& text_) : text(&text_) { }
    virtual bool can_reduce() { return true; }
    virtual std::string to_tibasic();
};

class InvokeType : public ParseData {
    Type const* type;
public:
    InvokeType(Type const* type_) : type(type_) {}
    virtual void preform_on(WrittenString& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
};

class InvokeVariable : public ParseData {
    Variable * var;
public:
    InvokeVariable(Variable * var_);
};

class UseOperator : public ParseData {
public:
};

class PlusOperand : public ParseData {
public:
    PlusOperand();
};

class EqualsOperand : public ParseData {
public:
    EqualsOperand();
};

class MinusOperand : public ParseData {
public:
    MinusOperand();
};

class StarOperand : public ParseData {
public:
    StarOperand();
};

class SlashOperand : public ParseData {
public:
    SlashOperand();
    void preform_on(InvokeVariable& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
    void preform_on(SlashOperand& next, ParsingLog& out, ErrorList& err_out, TypeMap& types, Scope* scope);
};

class AmpersandOperand : public ParseData {
public:
    AmpersandOperand();
};

class PipeOperand : public ParseData {
public:
    PipeOperand();
};

class PercentOperand : public ParseData {
public:
    PercentOperand();
};

class CarotOperand : public ParseData {
public:
    CarotOperand();
};

class TildeOperand : public ParseData {
public:
    TildeOperand();
};

class OpenParenthesis : public ParseData {
public:
    OpenParenthesis();
};

class CloseParenthesis : public ParseData {
public:
    CloseParenthesis();
};

class OpenCurly : public ParseData {
public:
    OpenCurly();
};

class CloseCurly : public ParseData {
public:
    CloseCurly();
};

class OpenSquare : public ParseData {
public:
    OpenSquare();
};

class CloseSquare : public ParseData {
public:
    CloseSquare();
};

class LessThan : public ParseData {
public:
    LessThan();
};

class GreaterThan : public ParseData {
public:
    GreaterThan();
};

class CommaOperand : public ParseData {
public:
    CommaOperand();
};

class DotOperand : public ParseData {
public:
    DotOperand();
};

class QuestionMark : public ParseData {
public:
    QuestionMark();
};

class ColonOperand : public ParseData {
public:
    ColonOperand();
};

class SemiColon : public ParseData {
public:
    SemiColon();
};

class StringLiteralParse : public ParseData {
private:
    StringLiteralParse();
};

class EndStringQuote : public StringLiteralParse {
    std::string const text;
public:
    EndStringQuote(std::string const& text_);
};

class EndStringApost : public StringLiteralParse {
    std::string const text;
public:
    EndStringApost(std::string const& text_);
};

class QuoteMark : public StringLiteralParse {
public:
    QuoteMark();
};

class ApostMark : public StringLiteralParse {
public:
    ApostMark();
};

class EscapeChar : public StringLiteralParse {
public:
    EscapeChar();
};














#endif /* ParseData_hpp */
