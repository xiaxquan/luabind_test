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
//static int isquare(lua_State* L);//�η�����
//static int alert(lua_State* L);//���溯��������lua����һ���ַ������������Ե����ķ�ʽ��ʾ����
//static const struct luaL_Reg funcs[] = {
//	{ "isquare",isquare },
//	{ "alert",alert },
//	{NULL,NULL}
//};//�����luaL_Reg���÷�������c����һ����lua���õ�������lua����Ϳ���ͨ���������ø�c����
//
////int luaopen_func(lua_State* L) {//�������ע�ắ��
////	lua_register(L, "func", funcs);//func����lua��table����
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
//static int isquare(lua_State *L) {              /* C�еĺ����� */
//	float rtrn = lua_tonumber(L, -1);      /* ��Lua�������ȡ��һ�����������������number���͵� */
//	//printf("Top of square(), nbr=%f\n",rtrn);
//	lua_pushnumber(L, rtrn*rtrn);           /* ������ֵѹ��Lua�������ջ�� */
//	return 1;                              /* �������ֵ����lua�������������ջ������˶��ٸ�����ֵ */
//}
void  greet()
{
	std::cout << "hello world!/n";
}
//
//static int luaopen_luabind_test(lua_State* L)
//{
//	lua_register(L, "luabind_test",(lua_CFunction)funcs);//func����lua��table����
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

extern "C" int __declspec(dllexport) isquare(lua_State *L) {              /* C�еĺ����� */
	float rtrn = lua_tonumber(L, -1);      /* ��Lua�������ȡ��һ�����������������number���͵� */
	//printf("Top of square(), nbr=%f\n",rtrn);
	lua_pushnumber(L, rtrn*rtrn);           /* ������ֵѹ��Lua�������ջ�� */
	return 1;                              /* �������ֵ����lua�������������ջ������˶��ٸ�����ֵ */
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
//	//	L,               /* Lua ״̬�� */
//	//	"square",        /*Lua�еĺ����� */
//	//	isquare          /*��ǰ�ļ��еĺ����� */
//	//);
//	//lua_register(L, "alert", alert);
//		//lua_register(L,"greet", greet);
//	return 0;
//}