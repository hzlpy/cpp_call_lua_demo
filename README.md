# cpp_call_lua_demo
A simple tutorial about calling lua in C++ program.

### Make

```
make  
make call_lua_func  
make lua_callback
```
 
### Run

```
./run_lua_file ../script/helloworld.lua
./call_lua_func ../script/callfunc.lua
./lua_callback ../script/callback.lua
```


### Tree
```
├── bin                    // bin
│   ├── call_lua_func
│   ├── lua_callback
│   └── run_lua_file
├── include                // include files
│   ├── lauxlib.h
│   ├── lua.h
│   ├── lua.hpp
│   └── lualib.h
├── lib                    // shared lib
│   └── liblua.a
├── obj
│   ├── call_lua_func.o
│   ├── lua_callback.o
│   ├── run_lua_file.o
│   └── runlua.o
├── README.md           
├── script                 // Lua scripts
│   ├── callback.lua
│   ├── callfunc.lua
│   └── helloworld.lua
└── src                    // .cpp source code
    ├── call_lua_func.cpp
    ├── lua_callback.cpp
    ├── Makefile
    └── run_lua_file.cpp

```
