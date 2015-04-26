#include <lua.h>
#include <lauxlib.h>
#include <string.h>
#include <stdlib.h>

//被lua调用的c接口的唯一函数原型：
//typedef int (*lua_CFunction) (lua_State* L);

static int lnum_add(lua_State* L)
{
    double a = lua_tonumber(L, 1);  //利用lua_tonumber获取参数
    double b = lua_tonumber(L, 2);

    lua_pushnumber(L, a + b);   //把返回值入栈
    return 1;   //表示返回的参数个数
}

static int lnum_square(lua_State* L)
{
    double n = lua_tonumber(L, 1);

    lua_pushnumber(L, n*n);
    return 1;
}

int luaopen_util(lua_State* L)
{
    luaL_checkversion(L);
    luaL_Reg lst[] = 
    {
        {"num_add", lnum_add},
        {"num_square", lnum_square},
        {NULL, NULL},
    };
    luaL_newlib(L, lst);
    return 1;
}
