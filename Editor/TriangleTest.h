#pragma once

#include "VertexBufferArray.h"
#include "Transform.h"
#include "GLSLLoader.h"
#include "Shader.h"

class TriangleTest
{
private:
	uint32_t			_u_offset;
	glm::vec3			offset;

	std::unique_ptr<Shader> shader;
	std::unique_ptr<VertexBufferArray> vao;
	std::shared_ptr<VertexBufferObject> vbo;
	std::shared_ptr<IndexBufferObject> ibo;

public:
	inline TriangleTest()
	{
		// Set up vertex data and buffer array
		Vertex v = Vertex(3, { VertexElement(3,		{ -0.5f, -0.5f, 0.0f,	// VERTEX POSITIONS
													   0.5f, -0.5f, 0.0f,
													   0.0f,  0.5f, 0.0f }) });

		std::vector<uint32_t> i = { 0, 1, 2 };

		vbo = std::make_shared<VertexBufferObject>(v);
		ibo = std::make_shared<IndexBufferObject>(i);

		std::vector< std::shared_ptr<VertexBufferObject>> vbos = { vbo };
		vao = std::make_unique<VertexBufferArray>(vbos, ibo);
		vao->Create();


		// Setup shader
		shader = std::make_unique<Shader>(GLSLLoader::LoadVertFrag("shaders/Diffuse.vs", "shaders/Diffuse.fs"));
		_u_offset = glGetUniformLocation(shader->GetBufferObject(), "pos_offset");
	}

	inline ~TriangleTest() {}

	inline void Render()
	{
		offset = glm::vec3(1.0f, 0.0f, 0.0f);

		shader->Bind();

		glUniform3fv(_u_offset, 1, glm::value_ptr(offset));

		vao->Bind();
		ibo->Bind();

		glDrawElements(GL_TRIANGLES, ibo->GetIndexSize(), GL_UNSIGNED_INT, 0);
	}
};