#ifndef MATERIAL_H
#define MATERIAL_H

#include "light.h"
#include "framework.h"
#include "shader.h"
#include "camera.h"
#include "mesh.h"


class Material {
public:

	Shader* shader = NULL;
	Texture* texture = NULL;
	vec4 color;
	vec3 Ka;
	vec3 Ks;
	vec3 Kd;
	float alpha;
	enum  eMatType { GENERIC, BLACKRUBBER, PEARL, GOLD };
	char matType;
	enum  eTexType { NORMAL, ROUGHNESS, METALNESS, COLOR, NONE };
	char texType;


	virtual void setUniforms(Camera* camera, Matrix44 model, Light* light) = 0;
	virtual void render(Mesh* mesh, Matrix44 model, Camera * camera, Light* light) = 0;
	virtual void renderInMenu(bool basic) = 0;
	virtual void setMaterial(eMatType material) = 0;
	virtual void setTex(eTexType texturetype);

};

class StandardMaterial : public Material {
public:

	StandardMaterial();
	~StandardMaterial();

	void setUniforms(Camera* camera, Matrix44 model, Light* light );
	void render(Mesh* mesh, Matrix44 model, Camera * camera, Light* light );
	void renderInMenu(bool basic);
	void setMaterial(eMatType material);
	void setTex(eTexType texturetype);
};

class WireframeMaterial : public StandardMaterial {
public:

	WireframeMaterial();
	~WireframeMaterial();

	void render(Mesh* mesh, Matrix44 model, Camera * camera);
};

#endif