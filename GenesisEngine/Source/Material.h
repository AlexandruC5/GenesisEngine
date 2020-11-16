#pragma once
#include "Component.h"
#include "Globals.h"

#include <string>

class GnMesh;
class ResourceMaterial;
class ResourceTexture;
class GnJSONArray;

class Material : public Component {
public: 
	Material();
	Material(GameObject* gameObject);
	~Material();

	void Update() override;
	void SetResourceUID(uint UID) override;

	void GenerateTextureBuffers();

	void Save(GnJSONArray& save_array) override;
	void Load(GnJSONObj& load_object) override;
	void OnEditor() override;

	void SetTexture(ResourceTexture* texture);
	void AssignCheckersImage();
	ResourceTexture* GetDiffuseTexture();
	void SetMesh(GnMesh* mesh);
	bool DeleteTexture();

private:
	bool checkers_image;

	ResourceMaterial* _resource;
	ResourceTexture* _diffuseTexture;
	uint _textureID;
};