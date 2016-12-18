#include "Rigidbody.h"



const Vertex3 & CRigidbody::GetDirectionVectorOfRigidbody()
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return this->mDirectionVector;
}

void CRigidbody::SetDirectionVectorOfRigidbody(const Vertex3 & directionVector)
{
	this->mDirectionVector = directionVector;
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
