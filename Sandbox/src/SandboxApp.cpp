#include <DoomClone.h>

class Sandbox : public DoomClone::Application {
public:
	Sandbox() {
	
	}

	~Sandbox() {
	
	}
};

DoomClone::Application* DoomClone::create_application() {
	return new Sandbox();
}