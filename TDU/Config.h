#pragma once
/*
																   TDU Config
	You can change whichever setting you want by changing the value, most things here are debug settings, at least until a config parser is implemented
*/

/*
	Logger settings
*/
inline const bool c_ConEnabled = true; // Enable debug console, if set to false AllocConsole wont be called, cout will still happen though
inline const bool c_ConShowAddresses = true; // Only useful when testing signatures (after the game updates or when adding new ones), should be disabled on release builds
inline const bool c_ConErrorsOnly = false; // Only show errors, ignore generic messages and addresses
