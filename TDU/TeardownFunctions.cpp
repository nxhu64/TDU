#include "TeardownFunctions.h"
#include "Signatures.h"
#include "MemoryFunctions.h"

void Teardown::Functions::GetAddresses()
{
	Teardown::Functions::Constructors::GetAddresses();
	Teardown::Functions::LuaFunctions::GetAddresses();
	Teardown::Functions::EntityFunctions::GetAddresses();
	Teardown::Functions::Utils::GetAddresses();
	Teardown::Mem::GetAddresses();
}