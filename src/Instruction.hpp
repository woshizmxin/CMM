/*
    Instruction.hpp
    ===============
        Enum class __Instruction implementation.
*/

#pragma once

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enum Class __Instruction
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum class __Instruction
{
    // Load
    __LDC,
    __LD,
    __ALD,

    // Store
    __ST,
    __AST,

    // Push, Pop
    __PUSH,
    __POP,

    // Jump
    __JMP,
    __JZ,

    // Arithmetic
    __ADD,
    __SUB,
    __MUL,
    __DIV,

    // Relationship
    __LT,
    __LE,
    __GT,
    __GE,
    __EQ,
    __NE,

    // I/O
    __IN,
    __OUT,

    // Address
    __ADDR,

    // Functional
    __CALL,
    __RET,
};


std::string instructionToString(__Instruction instruction) {
  switch (instruction) {
    case __Instruction::__LDC: return "__LDC";
    case __Instruction::__LD: return "__LD";
    case __Instruction::__ALD: return "__ALD";
    case __Instruction::__ST: return "__ST";
    case __Instruction::__AST: return "__AST";
    case __Instruction::__PUSH: return "__PUSH";
    case __Instruction::__POP: return "__POP";
    case __Instruction::__JMP: return "__JMP";
    case __Instruction::__JZ: return "__JZ";
    case __Instruction::__ADD: return "__ADD";
    case __Instruction::__SUB: return "__SUB";
    case __Instruction::__MUL: return "__MUL";
    case __Instruction::__DIV: return "__DIV";
    case __Instruction::__LT: return "__LT";
    case __Instruction::__LE: return "__LE";
    case __Instruction::__GT: return "__GT";
    case __Instruction::__GE: return "__GE";
    case __Instruction::__EQ: return "__EQ";
    case __Instruction::__NE: return "__NE";
    case __Instruction::__IN: return "__IN";
    case __Instruction::__OUT: return "__OUT";
    case __Instruction::__ADDR: return "__ADDR";
    case __Instruction::__CALL: return "__CALL";
    case __Instruction::__RET: return "__RET";
    default: return "Unknown Instruction";
  }
}


}  // End namespace CMM
