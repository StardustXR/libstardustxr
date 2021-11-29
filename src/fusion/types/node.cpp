#include "node.hpp"
#include "../fusion_internal.hpp"

namespace StardustXRFusion {

Node::Node() {}
Node::~Node() {
	if(destroyable) {
		messenger->sendSignal(
			getNodePath().c_str(),
			"destroy",
			FLEX_ARG(FLEX_NULL)
		);
	}
}

std::string Node::getNodePath() {
	return nodePath+"/"+nodeName;
}
std::string Node::getNodeName() {
	return nodeName;
}

void Node::setEnabled(bool enabled) {
	messenger->sendSignal(
		getNodePath().c_str(),
		"setEnabled",
		FLEX_ARG(FLEX_BOOL(enabled))
	);
}

} // namespace StardustXRFusion
