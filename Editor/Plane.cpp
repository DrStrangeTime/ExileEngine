#include "Plane.h"
#include "ContentManager.h"

Plane::Plane(uint32_t& shader_program, float x, float y, float z, uint16_t direction, float w, float h, uint32_t mat_id)
{
	_active = true;
	_dynamic = false;

	_type = A_STATIC_MESH;


	VertexData v = VertexData(5, {	VertexElement(3,	{	w / 2.f,  h / 2.f, 0.0f,		// VERTEX POSITIONS
															w / 2.f, -h / 2.f, 0.0f,
														   -w / 2.f, -h / 2.f, 0.0f,
														   -w / 2.f,  h / 2.f, 0.0f }),

									VertexElement(2,	{   1.0f, 1.0f,						// VERTEX TEXCOORDS
															1.0f, 0.0f,
															0.0f, 0.0f,
															0.0f, 1.0f }) });

	std::vector<uint32_t> i =							{	3, 2, 1,						// INDEX DATA
															3, 1, 0 };

	std::vector<MeshGroup> g = {	MeshGroup(mat_id,	OffsetData(0, 6)) };				// ELEMENT DATA

	_mesh_data = MeshData(1, v, i, g);

	//_vertex_data.vertexElements.reserve(1);
	//_vertex_data.vertexElements.emplace_back(VertexElement(3, {}));		// Create empty container for tangents
	//_vertex_data.vertexElements[3] = VertexOptimiser::PackTangents(indices, _vertex_data.vertexElements[2]);

	_vertex_buffer_object = std::make_shared<StaticVertexBufferObject>(_mesh_data.vertex_data);
	_index_buffer_object = std::make_shared<IndexBufferObject>(_mesh_data.index_data);

	std::vector<std::shared_ptr<VertexBufferObject>> vbos = { _vertex_buffer_object };

	_vertex_array_object = std::make_shared<VertexArrayObject>(vbos, _index_buffer_object);
	_vertex_array_object->Create();

	_trans.p = glm::vec3(x, y, z);

	if (direction == PLANE_DIR_X)
		_trans.r.y = 90.0f;
	else if (direction == PLANE_DIR_Y)
		_trans.r.z = 90.0f;

	MakeModel();

	_u_model = glGetUniformLocation(shader_program, "model");
}

void Plane::Render()
{
	glUniformMatrix4fv(_u_model, 1, GL_FALSE, glm::value_ptr(_trans.m));

	ContentManager::materials[_mesh_data.elements[0].mat_id]->Bind();

	_index_buffer_object->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
