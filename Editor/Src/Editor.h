#pragma once

#include "Headers.h"

//struct Object
//{
//	int t;
//	inline Object() { t = 0; }
//};
//
//struct Texture : Object
//{
//	inline Texture() { t = 1; }
//};
//
//struct Material : Object
//{
//	inline Material() { t = 2; }
//};
//
//struct StaticMesh : Object
//{
//	inline StaticMesh() { t = 3; }
//};



class Editor
{
public:
	//static std::vector<Object*> objects;

	static void Create();
	static void Destroy();
	static void Loop();

private:
	static void Update();
	static void Render();
};