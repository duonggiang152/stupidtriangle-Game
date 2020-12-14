#pragma once
#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Core/TimeStep.h"
namespace Hazel
{
	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach()  {}
		virtual void DeAttach()  {}
		virtual void OnUpdate(TimeStep ts)  {}
		virtual void OnImGuiLayer() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	private:
		std::string m_DebugName;
	};

	
}