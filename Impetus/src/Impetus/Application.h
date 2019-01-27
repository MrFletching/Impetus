#pragma once

#include "Impetus/Core.h"
#include "Impetus/Window.h"
#include "Impetus/LayerStack.h"
#include "Impetus/Events/ApplicationEvent.h"

namespace Impetus {

	class IMPETUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined by the client
	Application* CreateApplication();

}

