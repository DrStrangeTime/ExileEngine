#ifndef __FIXED_TIMESTEP_H__
#define __FIXED_TIMESTEP_H__

#define MICRO_SECOND	static_cast<double>(1000000.0)

#include "pch.h"
#include "ExCore.h"

namespace ExCore
{
	class EXILE_CORE_API Timestep
	{
	private:
		LARGE_INTEGER	start;
		LARGE_INTEGER	end;
		double			elapsed;
		double			ms;
		double			frames_per_second;
		double			r;

	public:
		Timestep() = default;
		Timestep(double fps, double rate);

		bool timeElapsed();

		double& GetFramesPerSecond();
		double& GetRate();

		void SetFramesPerSecond(double value);
		void SetRate(double value);
		void Start();
		void CalcLastElapsed();
		void ResetElapsed();
		void Lock();
	};
}

#endif