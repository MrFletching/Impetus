#pragma once

#include "Impetus/Core.h"
#include "Layer.h"

#include <vector>

namespace Impetus {

	class IMPETUS_API LayerStack
	{
		typedef std::list<Layer*> LayerList;
		typedef LayerList::iterator LayerListItr;

	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		LayerListItr begin() { return m_Layers.begin(); }
		LayerListItr end() { return m_Layers.end(); }

	private:
		LayerList m_Layers;
		LayerListItr m_LayerInsert;
	};

}