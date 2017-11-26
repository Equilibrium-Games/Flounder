#version 450

#extension GL_ARB_separate_shader_objects : enable

layout(binding = 0) uniform sampler2D samplerAlbedo;
layout(binding = 1) uniform sampler2D samplerBloom1;

layout(location = 0) in vec2 fragmentUv;

layout(location = 0) out vec4 outColour;

void main(void) 
{
	vec4 colour = texture(samplerAlbedo, fragmentUv);
	vec4 bloomColour = texture(samplerBloom1, fragmentUv);
	outColour = vec4(colour.rgb + bloomColour.rgb, 1.0f);
}
