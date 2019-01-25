#pragma once

#include "Application.h"

#ifdef IMPETUS_PLATFORM_WINDOWS

extern Impetus::Application* Impetus::CreateApplication();

int main(int argc, char** argv)
{
	Impetus::Log::Init();
	IMPETUS_CORE_WARN("Initialised Log");
	int a = 5;
	IMPETUS_INFO("Hello! Var={0}", a);

	auto app = Impetus::CreateApplication();
	app->Run();
	delete app;
}

#endif