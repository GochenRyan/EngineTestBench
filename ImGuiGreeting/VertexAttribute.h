#pragma once
#include <cstdint>
#include <type_traits>

enum class VertexAttributeType : uint8_t
{
	Position,
	Normal,
	Tangent,
	Bitangent,
	UV,
	Color,
	BoneWeight,
	BoneIndex,
};

enum class AttributeValueType : uint8_t
{
	Uint8,
	Float,
	Int16,
};

template<typename T>
static constexpr AttributeValueType GetAttributeValueType()
{
	if constexpr (std::is_same<T, uint8_t>())
	{
		return AttributeValueType::Uint8;
	}
	else if constexpr (std::is_same<T, uint16_t>())
	{
		return AttributeValueType::Int16;
	}
	else if constexpr (std::is_same<T, float>())
	{
		return AttributeValueType::Float;
	}
	else
	{
		return AttributeValueType::Float;
	}
}

struct VertexAttributeLayout
{
	VertexAttributeType vertexAttributeType;
	AttributeValueType attributeValueType;
	uint8_t attributeCount;
	uint8_t padding;
};
