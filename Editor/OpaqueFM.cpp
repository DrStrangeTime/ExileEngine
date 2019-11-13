#include "OpaqueFM.h"

OpaqueFM::OpaqueFM(uint32_t program, std::string name, bool masked, std::vector<std::shared_ptr<Texture>> textures)
{
	_name = name;
	_masked = masked;
	// FOR LOOP TO HARDCODE EACH TEXTURE HERE...
	_textures = textures;
	
	// Uniform setup here
}

void OpaqueFM::Bind()
{
	// Bind global material uniforms here...

	for (auto i = 0; i < _textures.size(); ++i)
		_textures[i]->Bind();
}
