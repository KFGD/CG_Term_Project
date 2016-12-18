#pragma once
#include "Utility.h"

class CRigidbody
{
public:
	const Vertex3& GetDirectionVectorOfRigidbody();
	void SetDirectionVectorOfRigidbody(const Vertex3& directionVector);

private:
	Vertex3 mDirectionVector;

public:
	CRigidbody();
	CRigidbody(const Vertex3& directionVector);
	CRigidbody(const CRigidbody& copyRigidbody);
	~CRigidbody();
	
	CRigidbody * Clone() const;
};

