#include <iostream>
#include "lua.hpp"

using namespace std;

void print_error(lua_State* state) {
    const char* message = lua_tostring(state, -1);
    cout << message << endl;
    lua_pop(state, 1);
}

void execute(const char* filename) {
    // Create a Lua state variable
    lua_State* state = luaL_newstate();
    // Load Lua libraries
    luaL_openlibs(state);
    // Load but don't run the Lua script
    int result;
    result = luaL_loadfile(state, filename);
 
    // Error out if file can't be read
    if (result != LUA_OK) { 
        print_error(state);
        return;
    }

    // Run the loaded Lua script
    result = lua_pcall(state, 0, 0, 0);

    // Error out if Lua file has an error
    if (result != LUA_OK) {
        print_error(state);
        return;
    }

    int a = 1;
    int b = 2;
    cout << "In C++, calling Lua function add(" << a <<"," << b << ")" << endl;    
    lua_getglobal(state, "add");
    // Pass all arguments to the Lua script on the stack
    lua_pushnumber(state, a);
    lua_pushnumber(state, b);
    result = lua_pcall(state, 2, 1, 0);
    if (result != LUA_OK) {
        print_error(state);
        return;
    }
    cout << "Back in C++ again." << endl;
    // Retrieve the return from the Lua script
    int number = lua_tonumber(state, -1);
    cout << "add(" << a << "," << b << ") = " << number << endl;
    cout << "In C++, calling Lua function isPositive(" << number << ")" << endl;
    lua_getglobal(state, "isPositive");
    // Pass all arguments to the Lua script on the stack
    lua_pushnumber(state, number);
    // Run the loaded Lua script
    result = lua_pcall(state, 1, 1, 0);
    if (result != LUA_OK) {
        print_error(state);
        return;
    }
    cout << "Back in C++ again." << endl;
    // Retrieve the return from the Lua script
    bool flag = lua_toboolean(state, -1);
    cout << "isPositive(" << number << ") = " << flag << endl;
    // Close the Lua state variable
    lua_close(state);
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        cout << "Usage: runlua file(s)" << endl;
        cout << "Loads and executes Lua programs." << endl;
        return 1;
    }

    for (int n=1; n<argc; ++n) {
        execute(argv[n]);
    }
    return 0;
}
