/*
    CMM
    ===
        CMM (C Minus Minus) Language Compiler And VM.
*/

#include "CMM.hpp"

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using CMM::Core;


////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    Core(argc, argv).Run();
}
