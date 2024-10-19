/*
    AST.h
    =====
        Struct __AST header.
*/

#pragma once

#include <string>
#include <vector>
#include "TokenType.hpp"
#include "Token.h"
#include <nlohmann/json.hpp>

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::vector;
using json = nlohmann::json;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class __AST
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class __AST
{
    // Friend
    friend class __SyntaxAnalyzer;
    friend class __SemanticAnalyzer;
    friend class __CodeGenerator;


public:

    // Constructor
    explicit __AST(__TokenType tokenType, const string &tokenStr = "", const vector<__AST *> &subList = {}, int lineNo = 0);


    // Constructor (With tokenPtr)
    explicit __AST(const __Token *tokenPtr);

    json toJson() const {
      json j;
      j["tokenType"] = tokenTypeToString(__tokenType); // 假设你想将枚举类型转换为整数
      j["tokenStr"] = __tokenStr;
      j["lineNo"] = __lineNo;

      // 转换子节点
      for (const auto& subAST : __subList) {
        if(subAST != nullptr){
          j["subList"].push_back(subAST->toJson());
        }
      }
      return j;
    }

    // Destructor
    ~__AST();


private:

    // Attribute
    __TokenType __tokenType;
    string __tokenStr;
    vector<__AST *> __subList;
    int __lineNo;
};


}  // End namespace CMM
