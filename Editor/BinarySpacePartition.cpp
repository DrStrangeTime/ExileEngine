#include "BinarySpacePartition.h"

void BinarySpacePartition::Inverse()
{
	// Inverse vertex data here... (x = -x)
}

VertexData& BinarySpacePartition::GetVertexData()
{
	return _vertex_data;
}

void BinarySpacePartition::SetMatID(uint32_t value)
{
	_mat_id = value;
}
