#pragma once
#include "core.h"

namespace DoomClone {
	class DoomClone_API Application {
	public:
		Application();
		virtual ~Application();
		void run();
	};

	Application* create_application();
}


