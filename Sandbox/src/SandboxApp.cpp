#include <Impetus.h>

class Sandbox : public Impetus::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Impetus::Application* Impetus::CreateApplication()
{
	return new Sandbox();
}