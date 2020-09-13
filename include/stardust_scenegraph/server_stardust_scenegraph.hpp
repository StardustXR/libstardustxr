#ifndef STARDUSTXR_SERVER_STARDUST_SCENEGRAPH_H
#define STARDUSTXR_SERVER_STARDUST_SCENEGRAPH_H

#include "../server/server_scenegraph.hpp"
#include "node.hpp"

namespace StardustXR {

class ServerStardustScenegraph : public ServerScenegraph {
public:
	ServerStardustScenegraph() : ServerScenegraph() {}

	void sendSignal(std::string path, std::string method, flexbuffers::Reference data);
	std::vector<uint8_t> executeMethod(std::string path, std::string method, flexbuffers::Reference args);

	void addNode(std::string path, Node *node);
protected:
	Node root;
	std::vector<uint8_t> executeMethod(std::string path, std::string method, flexbuffers::Reference args, bool returnValue);
	void onPathStep(std::string path, std::function<void(std::string)> pathStepFunction);
};

} // namespace StardustXR

#endif //STARDUSTXR_SERVER_STARDUST_SCENEGRAPH_H
