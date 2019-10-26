#pragma once

#include "VertexBufferArray.h"
#include "Transform.h"

class TriangleTest
{
private:
	uint32_t	_u_view;
	uint32_t	_u_proj;
	
	glm::mat4			view;
	glm::mat4			proj;
	Transform::Data		mod;

	std::unique_ptr<VertexBufferArray> vao;
	std::shared_ptr<VertexBufferObject> vbo;
	std::shared_ptr<IndexBufferObject> ibo;

public:
	inline TriangleTest()
	{
		Vertex v = Vertex({ VertexElement(3,		{	-.5f, -.5f, .0f,	// VERTEX POSITIONS
														.5f, -.5f, .0f,
														.0f, .5f, .0f } ) });

		std::vector<uint32_t> i = { 0, 1, 2 };


		vbo = std::make_shared<VertexBufferObject>(v);
		ibo = std::make_shared<IndexBufferObject>(i);

		std::vector< std::shared_ptr<VertexBufferObject>> vbos = { vbo };
		vao = std::make_unique<VertexBufferArray>(1, vbos, ibo);
		vao->Create();
	}

	inline ~TriangleTest()
	{
		vao->Destroy();
	}

	inline void Render()
	{
		// Shader stuff here

		vao->Bind();
		ibo->Bind();

		glDrawElements(GL_TRIANGLES, ibo->GetIndexSize(), GL_UNSIGNED_INT, 0);
	}
};