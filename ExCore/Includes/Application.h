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
	public:
		virtual void Update() = 0;
		virtual void Render(double& delta) = 0;
		virtual void Run() = 0;

		virtual bool isRunning() = 0;
	};
}

#endif