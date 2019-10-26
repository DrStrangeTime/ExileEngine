#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "pch.h"
#include "Hardware.h"
#include "InputEvent.h"
#include "Cursor.h"



namespace ExCore
{ 
	class EXILE_CORE_API Application
	{
	protected:
		int									width;
		int									height;
		const char*							title;
		GLFWwindow*							window;
		ExCore::RenderDevice::Properties	rdp;

	public:
		virtual void Create(int width, int height, const char* title, bool maximise, bool fullscreen, bool showCursor) = 0;
		virtual void Destroy() = 0;
		virtual void PollEvents() = 0;
		virtual void Swap() = 0;
		virtual void Run() = 0;
		virtual bool isRunning() = 0;

		int& GetWidth();
		int& GetHeight();
		const char* GetTitle();
		GLFWwindow* GetWindow();
		ExCore::RenderDevice::Properties& GetRenderDeviceProperties();

	};
}

#endif