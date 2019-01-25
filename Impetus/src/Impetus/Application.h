#pragma once

#include "Core.h"

namespace Impetus {

	class IMPETUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by the client
	Application* CreateApplication();

}
