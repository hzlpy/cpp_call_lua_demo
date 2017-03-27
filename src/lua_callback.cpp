#include <iostream>
#include "lua.hpp"

using namespace std;

int callback(lua_State* state) {
    int args = lua_gettop(state);
    cout << "callback() was called with arguments: " << args << endl;
    
    for (int n=1; n<=args; ++n) {
        cout << "argument " << n << ": " << lua_tostring(state, n) << endl;
    }

    lua_pushnumber(state, 123);
    return 1;
}

void print_error(lua_State* state) {
    const char* message = lua_tostring(state, -1);
    cout << message << endl;
    lua_pop(state, 1);
}

void execute(const char* filename) {
    lua_State* state = luaL_newstate();
    luaL_openlibs(state);
    lua_register(state, "callback", callback);
    int result;
    result = luaL_loadfile(state, filename);

    if (result != LUA_OK) {
        print_error(state);
        return;
    }

    result = lua_pcall(state, 0, LUA_MULTRET, 0);

    if (result != LUA_OK) {
        print_error(state);
        return;
    }
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
