#include "Graph.h"

class PathSearcher {
public:
  explicit PathSearcher() {}
  virtual ~PathSearcher() = default;

  // unified api, search shortest pathß 
  virtual bool search(const Graph&) = 0;

private:
};
