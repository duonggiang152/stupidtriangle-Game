#pragma once
#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"
namespace Hazel
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Height;
		unsigned int Width;
		

		WindowProps(const std::string& title = "Hazel Engine",
			unsigned int height = 1280,
			unsigned int width = 720) :
			Title(title), Width(width), Height(height)
		{

		}
	};
	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		/*virtual ~Window();*/

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// window attribute
		virtual	void SetEventCallBack(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props);
		
	};
}