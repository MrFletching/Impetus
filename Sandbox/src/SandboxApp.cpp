#include <Impetus.h>

class ExampleLayer : public Impetus::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		IMPETUS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Impetus::Event& event) override
	{
		IMPETUS_TRACE("ExampleLayer::OnEvent {0}", event);
	}
};

class Sandbox : public Impetus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Impetus::Application* Impetus::CreateApplication()
{
	return new Sandbox();
}