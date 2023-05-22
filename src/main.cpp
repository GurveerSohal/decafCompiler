#include <antlr4-runtime.h>

#include <iostream>

#include "ANTLRFileStream.h"
#include "CommonTokenStream.h"
#include "Decaf.h"
#include "DecafLexer.h"
#include "MyDecafVisitor.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage:\n\tdecaf_exec <input_file>" << std::endl;
        return 1;
    }

    antlr4::ANTLRFileStream afs;
    afs.loadFromFile(argv[1]);
    decaf::DecafLexer lexer(&afs);
    antlr4::CommonTokenStream tokens(&lexer);
    decaf::Decaf parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.file();

    decaf::MyDecafVisitor visitor;
    visitor.visit(tree);

    std::cout << "Hello world" << std::endl;

    return 0;
}