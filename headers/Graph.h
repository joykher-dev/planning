#include <memory>
#include <unordered_map>
#include <unordered_set>

#include "Types.h"

namespace planning {
	// alias 
	struct GraphNode;
	struct NodeLink;
	struct Hasher;
	using NodePtr = std::shared_ptr<GraphNode>;
	using NodeSet = std::unordered_set<NodeLink, Hasher>;

	struct NodeLink
	{
		explicit NodeLink(id_t from, id_t to, int16_t c)
			: from_id(from), to_id(to), cost(c) {}

		id_t from_id;
		id_t to_id;
		int16_t cost;

		// hash related 
		bool operator==(const NodeLink& n) const {
			return n.cost == cost && n.from_id == from_id && n.to_id == to_id;
		}
	};

	// hash related 
	struct Hasher
	{
		size_t operator()(const NodeLink& n) const noexcept {
			return std::hash<id_t>()(n.from_id) ^ std::hash<id_t>()(n.to_id) ^ std::hash<int16_t>()(n.cost);
		}
	};


	struct GraphNode
	{
		explicit GraphNode(id_t i, NodeSet s)
			: id(i), successors(s) {}

		id_t id;
		NodeSet successors; // with all same from_id
	};

	class Graph {
	public:
		explicit Graph(const std::unordered_set<NodePtr>& ns)
			: nodes(ns) {}

		virtual ~Graph() = default;

	private:
		std::unordered_set<NodePtr> nodes;
	};
}

