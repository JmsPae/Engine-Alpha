#pragma once

#include "Component.h"

class TestComponent : public alpha::Component {
public:
	TestComponent() {}

	void Init() override {
		printf("Initialized!\n");
	}

	void Update(float dt) override {
		printf("Updating!\n");
	}

	void Draw(alpha::Shader &shader) override {
		printf("Drawing!\n");
	}

	~TestComponent() {
		printf("Premature destructor! \n");
	}
};
