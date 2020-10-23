#pragma once

class GameObject;

enum class ComponentType {
	TRANSFORM,
	MESH,
	MATERIAL
};

class Component {
public: 
	Component();
	~Component();
	virtual void Update();
	virtual void Enable();
	virtual void Disable();

	virtual void OnEditor() = 0;
public:
	ComponentType type;

protected:
	bool enabled;

};
