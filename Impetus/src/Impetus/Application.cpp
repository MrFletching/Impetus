#include "impch.h"
#include "Application.h"

#include "Impetus/Events/ApplicationEvent.h"
#include "Impetus/Log.h"

namespace Impetus {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		IMPETUS_TRACE(e);

		while (true);
	}
}
