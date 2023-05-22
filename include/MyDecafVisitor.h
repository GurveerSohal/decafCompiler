#pragma once
#include "DecafBaseVisitor.h"


namespace decaf {

class  MyDecafVisitor : public DecafBaseVisitor {
public:
  std::any visitFile(Decaf::FileContext *ctx);

};

}  // namespace decaf
