#include "Rigidbody.h"



const Vertex3 & CRigidbody::GetDirectionVectorOfRigidbody()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return this->mDirectionVector;
}

void CRigidbody::SetDirectionVectorOfRigidbody(const Vertex3 & directionVector)
{
	this->mDirectionVector = directionVector;
}

void CRigidbody::AddDirectionVectorOfRigidbody(const Vertex3 & addDriectionVector)
{
	this->mDirectionVector.x += addDriectionVector.x;
	this->mDirectionVector.y += addDriectionVector.y;
	this->mDirectionVector.z += addDriectionVector.z;
}

CRigidbody::CRigidbody()
{
}

CRigidbody::CRigidbody(const Vertex3 & directionVector)
	:mDirectionVector(directionVector)
{
}

CRigidbody::CRigidbody(const CRigidbody & copyRigidbody)
	:mDirectionVector(copyRigidbody.mDirectionVector)
{
}


CRigidbody::~CRigidbody()
{
}

CRigidbody * CRigidbody::Clone() const
{
	return new CRigidbody(*this);
}
