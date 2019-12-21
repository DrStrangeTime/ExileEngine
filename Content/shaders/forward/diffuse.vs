#version 430

#extension GL_ARB_bindless_texture : require
#extension GL_ARB_gpu_shader5 : require 
#extension GL_ARB_gpu_shader_int64 : require

uniform mat4 model; 	// TEMP

layout (location = 0) in vec3 		aPos;
layout (location = 1) in vec3 		aTexCoord;
layout (location = 2) in vec3 		aNorm;
layout (location = 3) in uint64_t 	texHandle;

layout (std140, binding = 0) uniform Camera
{
    mat4 proj;
    mat4 view;
};

layout (std430, binding = 1) buffer Data
{
	float scaleX;
	float scaleY;
};

out block
{
	float ScaleX;
	float ScaleY;
	vec3 TexCoord;
	vec3 Normal;
} out_block;

flat out uint64_t TextureHandle;

void main()
{
	TextureHandle = texHandle;

	out_block.ScaleX = scaleX;
	out_block.ScaleY = scaleY;

	out_block.Normal = aNorm;
    out_block.TexCoord = vec3(aTexCoord.x, aTexCoord.y, 0.0);

    gl_Position = proj * view * model * vec4(aPos, 1.0);
}