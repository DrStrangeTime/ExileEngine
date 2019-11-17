#include "Plane.h"
#include "ContentManager.h"

Plane::Plane(float x, float y, float z, uint16_t direction, float w, float h, uint32_t mat_id)
{
	_mat_id = mat_id;
	_active = true;
	_dynamic = false;

	_type = A_STATIC_MESH;

	_vertex_data = VertexData(6, { VertexElement(3,		{	0.5f,  0.5f, 0.0f,				// VERTEX POSITIONS
															0.5f, -0.5f, 0.0f,
														   -0.5f, -0.5f, 0.0f,
														   -0.5f,  0.5f, 0.0f }),

									VertexElement(2,	{   1.0f, 1.0f,						// VERTEX TEXCOORDS
															1.0f, 0.0f,
															0.0f, 0.0f,
															0.0f, 1.0f }),

									VertexElement(1,	{   STATIC_CAST(float, mat_id),		// MATERIAL IDS
															STATIC_CAST(float, mat_id),
															STATIC_CAST(float, mat_id),
															STATIC_CAST(float, mat_id) }) });

	std::vector<uint32_t> indices =						{	0, 1, 3,						// INDEX DATA
															1, 2, 3 };

	//_vertex_data.vertexElements.emplace_back(VertexElement(3, {}));		// Create empty container for tangents
	//_vertex_data.vertexElements[3] = VertexOptimiser::PackTangents(indices, _vertex_data.vertexElements[2]);

	_vertex_buffer_object = std::make_shared<StaticVertexBufferObject>(_vertex_data);
	_index_buffer_object = std::make_shared<IndexBufferObject>(indices);

	std::vector<std::shared_ptr<VertexBufferObject>> vbos = { _vertex_buffer_object };

	_vertex_array_object = std::make_shared<VertexArrayObject>(vbos, _index_buffer_object);
	_vertex_array_object->Create();

	_trans.p = glm::vec3(x, y, z);

	if (direction == PLANE_DIR_X)
		_trans.r.y = 90.0f;
	else if (direction == PLANE_DIR_Y)
		_trans.r.z = 90.0f;

	Transform::MakeModel(_trans, _trans.m);
}

void Plane::Render()
{
	ContentManager::materials[_mat_id]->Bind();
	_index_buffer_object->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
