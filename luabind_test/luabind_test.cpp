#include <iostream>
#include <luabind/luabind.hpp>
#include <luabind/lua_include.hpp>
//
//extern "C"
//{
//#include "lua.h"
//#include "lauxlib.h"
//}
////#include "windows.h"
//using namespace luabind;
//static int isquare(lua_State* L);//次方函数
//static int alert(lua_State* L);//警告函数，它从lua接受一个字符串参数，并以弹窗的方式显示出来
//static const struct luaL_Reg funcs[] = {
//	{ "isquare",isquare },
//	{ "alert",alert },
//	{NULL,NULL}
//};//这就是luaL_Reg的用法，它给c函数一个供lua调用的名，在lua中你就可以通过该名调用该c函数
//
////int luaopen_func(lua_State* L) {//这个就是注册函数
////	lua_register(L, "func", funcs);//func就是lua中table的名
////	return 0;
////}
//
//static int alert(lua_State *L)
//{
//	const char * desc = lua_tostring(L, -1);
//	//MessageBox(NULL, desc, "alert", MB_OK);
//	return 1;
//}
//
//static int isquare(lua_State *L) {              /* C中的函数名 */
//	float rtrn = lua_tonumber(L, -1);      /* 从Lua虚拟机里取出一个变量，这个变量是number类型的 */
//	//printf("Top of square(), nbr=%f\n",rtrn);
//	lua_pushnumber(L, rtrn*rtrn);           /* 将返回值压回Lua虚拟机的栈中 */
//	return 1;                              /* 这个返回值告诉lua虚拟机，我们往栈里放入了多少个返回值 */
//}
void  greet()
{
	std::cout << "hello world!/n";
}
//
//static int luaopen_luabind_test(lua_State* L)
//{
//	lua_register(L, "luabind_test",(lua_CFunction)funcs);//func就是lua中table的名
//	open(L);
//	module(L)
//		[
//			def("greet", &greet)
//		];
//
//	return 0;
//}

//#include "stdio.h"
//#include "windows.h"
 
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
	using namespace luabind;


int  alert(lua_State *L)
{
	const char * desc = lua_tostring(L, -1);
	//MessageBox(NULL, desc, "alert", MB_OK);
	return 1;
}

extern "C" int __declspec(dllexport) isquare(lua_State *L) {              /* C中的函数名 */
	float rtrn = lua_tonumber(L, -1);      /* 从Lua虚拟机里取出一个变量，这个变量是number类型的 */
	//printf("Top of square(), nbr=%f\n",rtrn);
	lua_pushnumber(L, rtrn*rtrn);           /* 将返回值压回Lua虚拟机的栈中 */
	return 1;                              /* 这个返回值告诉lua虚拟机，我们往栈里放入了多少个返回值 */
}

//extern "C" int __declspec(dllexport) luaopen_add(lua_State *L)
//{
//	open(L);
//	module(L)
//		[
//			def("greet", &greet),
//			def("alert", &alert)
//		];
//	//lua_register(
//	//	L,               /* Lua 状态机 */
//	//	"square",        /*Lua中的函数名 */
//	//	isquare          /*当前文件中的函数名 */
//	//);
//	//lua_register(L, "alert", alert);
//		//lua_register(L,"greet", greet);
//	return 0;
//}