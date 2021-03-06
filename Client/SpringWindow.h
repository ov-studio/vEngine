#pragma once
#include "vEngine.h"

class ClientComponent;

class SpringWindow : public wi::gui::Window
{
public:
	void Create(ClientComponent* editor);

	wi::ecs::Entity entity;
	void SetEntity(wi::ecs::Entity entity);

	wi::gui::Button createButton;
	wi::gui::CheckBox debugCheckBox;
	wi::gui::CheckBox disabledCheckBox;
	wi::gui::CheckBox stretchCheckBox;
	wi::gui::CheckBox gravityCheckBox;
	wi::gui::Slider stiffnessSlider;
	wi::gui::Slider dampingSlider;
	wi::gui::Slider windSlider;
};

