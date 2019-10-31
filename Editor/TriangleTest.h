#pragma once

#include "VertexBufferArray.h"
#include "Transform.h"
#include "GLSLLoader.h"
#include "TextureLoader.h"
#include "Shader.h"
#include "Texture.h"

class TriangleTest
{
private:
	uint32_t albedo_tex;

	std::unique_ptr<Shader> shader;
	std::unique_ptr<Texture> texture;
	std::unique_ptr<VertexBufferArray> vao;
	std::shared_ptr<VertexBufferObject> vbo;
	std::shared_ptr<IndexBufferObject> ibo;

public:
	inline TriangleTest()
	{
		// Set up vertex data and buffer array
		Vertex v = Vertex(5, {	VertexElement(3,	{  0.5f,  0.5f, 0.0f,	// VERTEX POSITIONS
													   0.5f, -0.5f, 0.0f,
													  -0.5f, -0.5f, 0.0f,
													  -0.5f,  0.5f, 0.0f }),

								VertexElement(2,	{  1.0f, 1.0f,			// VERTEX TEXCOORDS
													   1.0f, 0.0f,
													   0.0f, 0.0f,
													   0.0f, 1.0f }) });

		std::vector<uint32_t> i = {					   0, 1, 3,				// INDEX DATA
													   1, 2, 3 };

		vbo = std::make_shared<VertexBufferObject>(v);
		ibo = std::make_shared<IndexBufferObject>(i);

		std::vector< std::shared_ptr<VertexBufferObject>> vbos = { vbo };
		vao = std::make_unique<VertexBufferArray>(vbos, ibo);
		vao->Create();

		// -------------------------------------------- DEBUG --------------------------------------------
		// -----------------------------------------------------------------------------------------------

		// Setup shader
		shader = std::make_unique<Shader>(GLSLLoader::LoadVertFrag("shaders/Diffuse.vs", "shaders/Diffuse.fs"));
		shader->Bind();

		texture = std::make_unique<Texture>(	shader->GetBufferObject(),
												TextureLoader::LoadTexture2D("textures/test.jpg"),
												GL_TEXTURE0,
												"albedoTex");
	}

	inline ~TriangleTest() {}

	inline void Render()
	{
		texture->Bind();
		shader->Bind();
		vao->Bind();
		glDrawElements(GL_TRIANGLES, ibo->GetIndexSize(), GL_UNSIGNED_INT, 0);
	}
};