#pragma once

#include "Application.h"

#ifdef IM_PLATFORM_WINDOWS

extern Impetus::Application* Impetus::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Impetus::CreateApplication();
	app->Run();
	delete app;
}

#endif