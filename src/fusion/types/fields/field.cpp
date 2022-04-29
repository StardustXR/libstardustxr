#include "../../fusion_internal.hpp"
#include "../../flex.hpp"

#include "field.hpp"
#include "values.hpp"

namespace StardustXRFusion {

Field::Field() : Spatial(false) {}

void Field::distance(Spatial *space, Vec3 point, std::function<void(float distance)> callback) {
	std::string spacePath = (space) ? space->getNodePath() : "";
	messenger->executeRemoteMethod(
		getNodePath().c_str(),
		"distance",
		FLEX_ARGS(
			FLEX_STRING(spacePath)
			FLEX_VEC3(point)
		),
		[callback](flexbuffers::Reference data) {
			callback(data.AsFloat());
		}
	);
}

void Field::normal(Spatial *space, Vec3 point, std::function<void (Vec3)> callback) {
	std::string spacePath = (space) ? space->getNodePath() : "";
	messenger->executeRemoteMethod(
		getNodePath().c_str(),
		"normal",
		FLEX_ARGS(
			FLEX_STRING(spacePath)
			FLEX_VEC3(point)
		),
		[callback](flexbuffers::Reference data) {
			callback(STARDUST_VEC3(data.AsVector()));
		}
	);
}

void Field::closestPoint(Spatial *space, Vec3 point, std::function<void (Vec3)> callback) {
	std::string spacePath = (space) ? space->getNodePath() : "";
	messenger->executeRemoteMethod(
		getNodePath().c_str(),
		"distance",
		FLEX_ARGS(
			FLEX_STRING(spacePath)
			FLEX_VEC3(point)
		),
		[callback](flexbuffers::Reference data) {
			callback(STARDUST_VEC3(data.AsVector()));
		}
	);
}

} // namespace StardustXRFusion
