#include "pch.h"
#include "FixedTimestep.h"

ExCore::Timestep::Timestep(double fps)
{
	elapsed = 0;
	frames_per_second = fps;
	ms = MICRO_SECOND / fps;	// Syncs updates at 60 per second (59 - 61)

	Start();
}

double& ExCore::Timestep::GetFramesPerSecond()
{
	return frames_per_second;
}

void ExCore::Timestep::SetFramesPerSecond(double value)
{
	frames_per_second = value;
}

void ExCore::Timestep::SetRate(double value)
{
	r = value;
}

// Start recording current time (called outside of while loop)
void ExCore::Timestep::Start()
{
	QueryPerformanceCounter(&end);
}

void ExCore::Timestep::CalcLastElapsed()
{
	QueryPerformanceCounter(&start);
	elapsed += (double)(start.QuadPart - end.QuadPart) / ms;
}

void ExCore::Timestep::ResetElapsed()
{
	elapsed -= 1.0;
}

void ExCore::Timestep::Lock()
{
	end = start;
}

bool ExCore::Timestep::timeElapsed()
{
	return (elapsed >= 1.0);
}
