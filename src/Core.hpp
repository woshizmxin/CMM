/*
    Core.hpp
    ========
        Class Core implementation.
*/

#pragma once

#include <string>
#include <iostream>
#include <boost/program_options.hpp>
#include "Core.h"
#include "LexicalAnalyzer.h"
#include "SyntaxAnalyzer.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"
#include "IO.h"
#include "VM.h"
#include "Constants.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::cout;
using std::endl;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Core::Core(int argc, char **argv):
    __ARGC(argc),
    __ARGV(argv) {}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::main()
{
    __main();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Input Arguments
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__inputArguments()
{
    namespace po = boost::program_options;

    po::options_description desc(__Constants::__DESCRIPTION_STR);

    desc.add_options()

        ("help,h", "show this help message and exit")

        (",i", po::value<string>(&__cmmFilePath),
            "Input CMM File Path")

        (",o", po::value<string>(&__outputFilePath)->default_value("a.out"),
            "Output ASM File Path")

        (",r", po::value<string>(&__asmFilePath),
            "Input ASM File Path (For Running)");

    po::variables_map vm;
    po::store(po::parse_command_line(__ARGC, __ARGV, desc), vm);

    if (vm.count("help"))
    {
        cout << desc << endl;
        exit(1);
    }

    po::notify(vm);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generate Code
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__generateCode() const
{
    if (!__cmmFilePath.empty())
    {
        auto tokenList   = __LexicalAnalyzer(__cmmFilePath).__lexicalAnalysis();
        auto root        = __SyntaxAnalyzer(tokenList).__syntaxAnalysis();
        auto j = root->toJson();
//        cout << j.dump(4) << endl; // 美化输出 JSON

        auto symbolTable = __SemanticAnalyzer(root).__semanticAnalysis();
//        printNestedMap(symbolTable);

        auto codeList    = __CodeGenerator(root, symbolTable).__generateCode();

        __IO::__outputInstruction(__outputFilePath, codeList);

        delete root;
    }
}

void Core::printNestedMap(unordered_map<string, unordered_map<string, pair<int, int>>>& nestedMap) const{
  for (const auto& outerPair : nestedMap) {
    const string& outerKey = outerPair.first;
    const unordered_map<string, pair<int, int>>& innerMap = outerPair.second;

    cout << "Outer Key: " << outerKey << endl;
    for (const auto& innerPair : innerMap) {
      const string& innerKey = innerPair.first;
      const pair<int, int>& value = innerPair.second;
      cout << "  Inner Key: " << innerKey << ", Value: (" << value.first << ", " << value.second << ")" << endl;
    }
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Exec Code
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__execCode() const
{
    if (!__asmFilePath.empty())
    {
        auto codeList = __IO::__parseInstructionFile(__asmFilePath);

        __VM(codeList).__run();
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__main()
{
    __inputArguments();
    __generateCode();
    __execCode();
}


}  // End namespace CMM
