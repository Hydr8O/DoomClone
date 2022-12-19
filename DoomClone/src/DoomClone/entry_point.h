#pragma once

#ifdef DC_PLATFORM_WINDOWS

extern DoomClone::Application* DoomClone::create_application();

int main(int argc, char** argv) {
	auto app = DoomClone::create_application();
	app->run();
	delete app;
}

#endif
