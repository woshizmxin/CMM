/*
    CodeGenerator.h
    ===============
        Class CodeGenerator header.
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include "AST.h"
#include "Instruction.hpp"

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::vector;
using std::unordered_map;
using std::pair;


////////////////////////////////////////////////////////////////////////////////
// Class CodeGenerator
////////////////////////////////////////////////////////////////////////////////

class CodeGenerator
{
public:

    // Constructor
    CodeGenerator(AST *root = nullptr,
        const unordered_map<string, unordered_map<string, pair<int, int>>> &symbolTable = {});


    // Generate Code
    vector<pair<Instruction, string>> generateCode();


private:

    // Attribute
    AST *__root;
    unordered_map<string, unordered_map<string, pair<int, int>>> __symbolTable;
    string __curFuncName;


    // Generate Number Code
    vector<pair<Instruction, string>> __generateNumberCode(AST *root) const;


    // Generate CompoundStmt Code
    vector<pair<Instruction, string>> __generateCompoundStmtCode(AST *root) const;


    // Generate StmtList Code
    vector<pair<Instruction, string>> __generateStmtListCode(AST *root) const;


    // Generate Stmt Code
    vector<pair<Instruction, string>> __generateStmtCode(AST *root) const;


    // Generate IfStmt Code
    vector<pair<Instruction, string>> __generateIfStmtCode(AST *root) const;


    // Generate WhileStmt Code
    vector<pair<Instruction, string>> __generateWhileStmtCode(AST *root) const;


    // Generate ReturnStmt Code
    vector<pair<Instruction, string>> __generateReturnStmtCode(AST *root) const;


    // Generate Expr Code
    vector<pair<Instruction, string>> __generateExprCode(AST *root) const;


    // Generate Var Code
    vector<pair<Instruction, string>> __generateVarCode(AST *root) const;


    // Generate SimpleExpr Code
    vector<pair<Instruction, string>> __generateSimpleExprCode(AST *root) const;


    // Generate RelOp Code
    vector<pair<Instruction, string>> __generateRelOpCode(AST *root) const;


    // Generate AddExpr Code
    vector<pair<Instruction, string>> __generateAddExprCode(AST *root) const;


    // Generate AddOp Code
    vector<pair<Instruction, string>> __generateAddOpCode(AST *root) const;


    // Generate Term Code
    vector<pair<Instruction, string>> __generateTermCode(AST *root) const;


    // Generate MulOp Code
    vector<pair<Instruction, string>> __generateMulOpCode(AST *root) const;


    // Generate Factor Code
    vector<pair<Instruction, string>> __generateFactorCode(AST *root) const;


    // Generate Call Code
    vector<pair<Instruction, string>> __generateCallCode(AST *root) const;


    // Generate ArgList Code
    vector<pair<Instruction, string>> __generateArgListCode(AST *root) const;


    // Generate Assign Code
    vector<pair<Instruction, string>> __generateAssignCode(AST *root) const;


    // Generate Global Variable Code
    vector<pair<Instruction, string>> __generateGlobalVariableCode() const;


    // Generate Main Prepare Code
    vector<pair<Instruction, string>> __generateMainPrepareCode() const;


    // Generate Global Code
    vector<pair<Instruction, string>> __generateGlobalCode() const;


    // Create CodeMap
    unordered_map<string, vector<pair<Instruction, string>>> __createCodeMap();


    // Create FuncJmpMap
    unordered_map<string, int> __createFuncJmpMap(
        const unordered_map<string, vector<pair<Instruction, string>>> &codeMap) const;


    // Translate Call Helper
    void __translateCallHelper(vector<pair<Instruction, string>> &codeList,
        int &IP, const unordered_map<string, int> &funcJmpMap) const;


    // Translate Call
    void __translateCall(
        unordered_map<string, vector<pair<Instruction, string>>> &codeMap,
        const unordered_map<string, int> &funcJmpMap) const;


    // Merge Code Map
    static vector<pair<Instruction, string>> __mergeCodeMap(
        const unordered_map<string, vector<pair<Instruction, string>>> &codeMap);


    // Generate Code
    vector<pair<Instruction, string>> __generateCode();
};


}  // End namespace CMM
