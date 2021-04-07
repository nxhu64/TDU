#pragma once

// Entity name	| Hex size	| Size in bytes	| Entity ID
// Invalid		|	?		|	?			|	1
// Scene		|	0xF8	|	248 bytes	|	2
// Environment	|	0xF8	|	248 bytes	|	3
// Group		|	0xF8	|	248 bytes	|	4
// Compound		|	0xF8	|	248 bytes	|	5
// Instance		|	0xF8	|	248 bytes	|	6
// Body			|	0xF8	|	248 bytes	|	7
// ?			|	?		|	?			|	8
// Vox			|	0xF8	|	248 bytes	|	9
// Light		|	0xF8	|	248 bytes	|	10
// Spawnpoint	|	0xF8	|	248 bytes	|	11
// Location		|	0xF8	|	248 bytes	|	12
// Enemy		|	0xF8	|	248 bytes	|	13
// VoxScript	|	0x120	|	288b bytes	|	14
// Joint		|	0xF8	|	248 bytes	|	15
// Water		|	0x3E8	|	1000 bytes	|	16
// VoxBox		|	0x168	|	360 bytes	|	17
// Voxagon		|	0x1F0	|	496 bytes	|	18
// Rope			|	0xF8	|	248 bytes	|	19
// Boundary		|	0x188	|	392 bytes	|	20
// Vehicle		|	0xF8	|	248 bytes	|	21
// Wheel		|	0xF8	|	248 bytes	|	22
// Screen		|	0xF8	|	248 bytes	|	23
// Trigger		|	0x188	|	392 bytes	|	24
// Script		|	0xF8	|	248 bytes	|	25
// Count		|	?		|	? bytes		|	26

// Other sizes:
// Entity		|	0xF8	|	248 bytes

namespace Editor
{
	class Entity
	{
	public:
		void* pParamList; //0x0008
		char pad_0010[16]; //0x0010
		void* pParamValues; //0x0020
		char pad_0028[204]; //0x0028
		int Type; //0x00F4

		virtual void Destroy(Editor::Entity* Entity, bool free);
		virtual void emptyFunc();
		virtual void Function2();
		virtual void Function3();
		virtual void emptyFunc2();
		virtual void emptyFunc3();
	}; //Size: 0x00F8

	class Instance : public Editor::Entity
	{

	};
}