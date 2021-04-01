/*
	TDU Configuration file
	
	You can add your own configuration values here, just define them and then check them using the #if directive
	
	To-do: Add more configurable values, so that users don't need to edit CPP files, and instead edit stuff here (i.e. keybinds)
*/


/*
	Console settings
*/

// Show console / disable this if for some reason you don't want it
#define SHOW_CONSOLE

// Only useful when the game updates, so you can see which functions the signatures no longer work for
//#define PRINT_ADDRESSES

// Only print errors, ignore generic messages, addresses (this value overrides PRINT_ADDRESSES), and other stuff (Doesn't disable Lua's print cout)
//#define PRINT_ERRORS_ONLY

/*
	Lua settings
*/

// Open the debug lib
#define ENABLE_DEBUG_LIB

// Open the OS lib (Not recommended, unless you're running scripts you really trust)
//#define ENABLE_OS_LIB

// Open the IO lib
//#define ENABLE_IO_LIB