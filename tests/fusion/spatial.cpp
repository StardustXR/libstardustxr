#include "fusion/fusion.hpp"
#include "fusion/types/drawable/model.hpp"

using namespace StardustXRFusion;
using namespace SKMath;

int main(int, char *[]) {
	StardustXRFusion::Setup();

	double time = 0;
	double rotationSeconds = 5;

	Spatial gyroRoot(StardustXRFusion::Root(), vec3_zero, quat_identity, vec3_one, true, true, false, true);
	Model outsideRing(&gyroRoot, "../../../res/gyro_outside.glb");
	Model middleRing(&outsideRing, "../../../res/gyro_middle.glb");
	Model insideRing(&middleRing, "../../../res/gyro_inside.glb");
	Model gem(&gyroRoot, "../../../res/gyro_gem.glb");

	OnLogicStep([&](double delta, double) {
		time += delta;
		double rotation = 360*time/rotationSeconds;

		gyroRoot.setOrigin(vec3_up * std::sin(rotation*deg2rad) * 0.1f);
		gem.setScale(vec3_one * (1.0f + std::sin(rotation*deg2rad*2) * 0.25f));

		outsideRing.setOrientation(quat_from_angles(0, 0, rotation));
		middleRing.setOrientation(quat_from_angles(rotation, 0, 0));
		insideRing.setOrientation(quat_from_angles(0, 0, rotation));
	});
	StardustXRFusion::StallMainThread();
}
