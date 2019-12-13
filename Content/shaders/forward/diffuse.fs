#version 430

#extension GL_ARB_bindless_texture : require
#extension GL_ARB_gpu_shader5 : require 
#extension GL_ARB_gpu_shader_int64 : require

layout (location = 0, index = 0) out vec4 colour;

in block
{
    vec3 TexCoord;
    vec3 Normal;
} in_block;

flat in uint64_t TextureHandle;

void main()
{
    sampler2D tex_map = sampler2D(TextureHandle);

    colour = texture(tex_map, vec2(in_block.TexCoord.s, in_block.TexCoord.t));
}