/*
    TokenType.hpp
    =============
        Enum class __TokenType implementation.
*/

#pragma once

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enum Class __TokenType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum class __TokenType
{
    // Word
    __Id,                  // Id
    __Number,              // Number

    // Keyword
    __Void,                // void
    __Int,                 // int
    __If,                  // if
    __Else,                // else
    __While,               // while
    __Return,              // return

    // Operator
    __Plus,                // +
    __Minus,               // -
    __Multiply,            // *
    __Divide,              // /
    __Less,                // <
    __LessEqual,           // <=
    __Greater,             // >
    __GreaterEqual,        // >=
    __Equal,               // ==
    __NotEqual,            // !=
    __Assign,              // =
    __Semicolon,           // ;
    __Comma,               // ,
    __LeftRoundBracket,    // (
    __RightRoundBracket,   // )
    __LeftSquareBracket,   // [
    __RightSquareBracket,  // ]
    __LeftCurlyBracket,    // {
    __RightCurlyBracket,   // }

    // End
    __END,                 // END

    // Ast
    __Program,             // AST: Program
    __VarDecl,             // AST: VarDecl
    __FuncDecl,            // AST: FuncDecl
    __ParamList,           // AST: ParamList
    __Param,               // AST: Param
    __LocalDecl,           // AST: LocalDecl
    __StmtList,            // AST: StmtList
    __IfStmt,              // AST: IfStmt
    __WhileStmt,           // AST: WhileStmt
    __ReturnStmt,          // AST: ReturnStmt
    __Expr,                // AST: Expr
    __Var,                 // AST: Var
    __SimpleExpr,          // AST: SimpleExpr
    __AddExpr,             // AST: AddExpr
    __Term,                // AST: Term
    __Call,                // AST: Call
    __ArgList,             // AST: ArgList
};


std::string tokenTypeToString(__TokenType tokenType) {
  switch (tokenType) {
    case __TokenType::__Id: return "__Id";
    case __TokenType::__Number: return "__Number";
    case __TokenType::__Void: return "__Void";
    case __TokenType::__Int: return "__Int";
    case __TokenType::__If: return "__If";
    case __TokenType::__Else: return "__Else";
    case __TokenType::__While: return "__While";
    case __TokenType::__Return: return "__Return";
    case __TokenType::__Plus: return "__Plus";
    case __TokenType::__Minus: return "__Minus";
    case __TokenType::__Multiply: return "__Multiply";
    case __TokenType::__Divide: return "__Divide";
    case __TokenType::__Less: return "__Less";
    case __TokenType::__LessEqual: return "__LessEqual";
    case __TokenType::__Greater: return "__Greater";
    case __TokenType::__GreaterEqual: return "__GreaterEqual";
    case __TokenType::__Equal: return "__Equal";
    case __TokenType::__NotEqual: return "__NotEqual";
    case __TokenType::__Assign: return "__Assign";
    case __TokenType::__Semicolon: return "__Semicolon";
    case __TokenType::__Comma: return "__Comma";
    case __TokenType::__LeftRoundBracket: return "__LeftRoundBracket";
    case __TokenType::__RightRoundBracket: return "__RightRoundBracket";
    case __TokenType::__LeftSquareBracket: return "__LeftSquareBracket";
    case __TokenType::__RightSquareBracket: return "__RightSquareBracket";
    case __TokenType::__LeftCurlyBracket: return "__LeftCurlyBracket";
    case __TokenType::__RightCurlyBracket: return "__RightCurlyBracket";
    case __TokenType::__END: return "__END";
    case __TokenType::__Program: return "__Program";
    case __TokenType::__VarDecl: return "__VarDecl";
    case __TokenType::__FuncDecl: return "__FuncDecl";
    case __TokenType::__ParamList: return "__ParamList";
    case __TokenType::__Param: return "__Param";
    case __TokenType::__LocalDecl: return "__LocalDecl";
    case __TokenType::__StmtList: return "__StmtList";
    case __TokenType::__IfStmt: return "__IfStmt";
    case __TokenType::__WhileStmt: return "__WhileStmt";
    case __TokenType::__ReturnStmt: return "__ReturnStmt";
    case __TokenType::__Expr: return "__Expr";
    case __TokenType::__Var: return "__Var";
    case __TokenType::__SimpleExpr: return "__SimpleExpr";
    case __TokenType::__AddExpr: return "__AddExpr";
    case __TokenType::__Term: return "__Term";
    case __TokenType::__Call: return "__Call";
    case __TokenType::__ArgList: return "__ArgList";
    default: return "Unknown TokenType";
  }
}


}  // End namespace CMM
