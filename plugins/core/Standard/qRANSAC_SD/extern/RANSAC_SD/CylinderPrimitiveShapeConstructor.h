#ifndef CYLINDERPRIMITIVESHAPECONSTRUCTOR_HEADER
#define CYLINDERPRIMITIVESHAPECONSTRUCTOR_HEADER
#include "PrimitiveShapeConstructor.h"
#include "CylinderPrimitiveShape.h"

#ifndef DLL_LINKAGE
#define DLL_LINKAGE
#endif

class DLL_LINKAGE CylinderPrimitiveShapeConstructor
: public PrimitiveShapeConstructor
{
	public:
		CylinderPrimitiveShapeConstructor(float minCylinderRadius = -std::numeric_limits<float>::infinity()
			, float maxCylinderRadius = std::numeric_limits< float >::infinity()
			, float maxCylinderLength = std::numeric_limits< float >::infinity());
		size_t Identifier() const;
		unsigned int RequiredSamples() const;
		PrimitiveShape *Construct(const MiscLib::Vector< Vec3f > &points,
			const MiscLib::Vector< Vec3f > &normals) const;
		PrimitiveShape *Construct(const MiscLib::Vector< Vec3f > &samples) const;
		PrimitiveShape *Deserialize(std::istream *i, bool binary = true) const;
		size_t SerializedSize() const;
	private:
		float m_maxCylinderRadius;
		float m_minCylinderRadius;
		float m_maxCylinderLength;
};

#endif
