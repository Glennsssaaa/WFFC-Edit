#include "DisplayObject.h"
#include <string>
#include <iostream>

DisplayObject::DisplayObject()
{
	m_model = NULL;
	m_texture_diffuse = NULL;
	m_orientation.x = 0.0f;
	m_orientation.y = 0.0f;
	m_orientation.z = 0.0f;
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = 0.0f;
	m_scale.x = 0.0f;
	m_scale.y = 0.0f;
	m_scale.z = 0.0f;
	m_render = true;
	m_wireframe = false;

	m_light_type =0;
	m_light_diffuse_r = 0.0f;	m_light_diffuse_g = 0.0f;	m_light_diffuse_b = 0.0f;
	m_light_specular_r = 0.0f;	m_light_specular_g = 0.0f;	m_light_specular_b = 0.0f;
	m_light_spot_cutoff = 0.0f;
	m_light_constant = 0.0f;
	m_light_linear = 0.0f;
	m_light_quadratic = 0.0f;
}


DisplayObject::~DisplayObject()
{
//	delete m_texture_diffuse;
}

void DisplayObject::HighlightObject(bool state) {

	
	m_model->UpdateEffects([&](DirectX::IEffect* effect) {
		auto fog = dynamic_cast<DirectX::IEffectFog*>(effect);
	if (fog) {
		fog->SetFogEnabled(!state);
		fog->SetFogStart(0);
		fog->SetFogEnd(8);
		fog->SetFogColor(DirectX::Colors::White);
	}});
}
