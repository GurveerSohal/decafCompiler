#include "MyDecafVisitor.h"

using namespace std;

namespace decaf {

std::any MyDecafVisitor::visitFile(Decaf::FileContext *ctx) {
    cout << "It does something" << endl;
    return 0;
}

}