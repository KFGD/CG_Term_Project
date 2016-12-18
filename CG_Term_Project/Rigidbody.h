#pragma once
#include "Utility.h"

class CRigidbody
{
public:
	const Vertex3& GetDirectionVectorOfRigidbody();
	void SetDirectionVectorOfRigidbody(const Vertex3& directionVector);
	void AddDirectionVectorOfRigidbody(const Vertex3& addDriectionVector);

private:
	Vertex3 mDirectionVector;

public:
	CRigidbody();
	CRigidbody(const Vertex3& directionVector);
	CRigidbody(const CRigidbody& copyRigidbody);
	~CRigidbody();
	
	CRigidbody * Clone() const;
};

