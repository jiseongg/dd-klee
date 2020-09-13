
#ifndef KLEE_FEATURE_H
#define KLEE_FEATURE_H

#include "klee/ExecutionState.h"

#include <map>
#include <vector>

using namespace klee;

namespace klee {
  class Executor;

class Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states) = 0;
};

class NXTInstExternalFunctionCall : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class NXTInstFPOperation : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class NXTInstAggregateOperation : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class NXTInstVectorOperation : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class NXTInstSwitchWithSym : public Feature {
  Executor &executor;
public:
  NXTInstSwitchWithSym(Executor &_executor);
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class NXTInstAllocaWithSym : public Feature {
  Executor &executor;
public:
  NXTInstAllocaWithSym(Executor &_executor);
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class NXTInstIndirectBrWithSym : public Feature {
  // NOTE: const reference type cannot call executor.toUnique
  Executor &executor;
public:
  NXTInstIndirectBrWithSym(Executor &_executor);
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class SmallestInstructionStepped : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class SmallestInstructionsSinceCovNew : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class SmallestCallPathInstruction : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class ClosestToUncoveredInst : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class SmallestSymbolics : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class LargestSymbolics : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class HighestNumOfConstExpr : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class HighestNumOfSymExpr : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class LowestQueryCost : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class ShallowestState : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class DeepestState : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

class ShortestConstraints : public Feature {
public:
  virtual std::vector<bool> operator()(const std::vector<ExecutionState*> &states);
};

} // End klee namespace

#endif /* KLEE_FEATURE_H */