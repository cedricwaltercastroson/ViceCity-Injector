#pragma warning(disable: 4200)

// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>

#define A 0x41
#define B 0x42
#define C 0x43
#define D 0x44
#define E 0x45
#define F 0x46
#define G 0x47
#define H 0x48
#define I 0x49
#define J 0x4A
#define K 0x4B
#define L 0x4C
#define M 0x4D
#define N 0x4E
#define O 0x4F
#define P 0x50
#define Q 0x51
#define R 0x52
#define S 0x53
#define T 0x54
#define U 0x55
#define V 0x56
#define W 0x57
#define X 0x58
#define Y 0x59
#define Z 0x5A

float MAX_HP = 200.0f;
float MAX_ARMOUR = 200.0f;
unsigned long int MAX_MONEY= 999999999;
int MAX_AMMO = 100;
int MAX_MAG = 100;

struct player_resource {
	float HP;
	float ARMOUR;
};

struct money_resource {
	unsigned long int MONEY;
};

struct ammo_resource {
	int AMMO;
	int MAG;
};

struct memory_ptr {
	DWORD64 base_address;
	int total_offsets;
	int offsets[];
};

memory_ptr player_resource_hack_ptr = {
		0x4CCCAA0,
			1,
	{0x4DC}
};

memory_ptr money_hack_ptr = {
		0x4CCCB70,
			0,
	{ 0x0 }
};

memory_ptr ammo_resource_hack_ptr = {
		0x4CCCAA0,
			1,
	{0x6C8}
};

//pointer to resource struct
player_resource* player_resource_hack;
money_resource* money_resource_hack;
ammo_resource* ammo_resource_hack;

// get module base address
HMODULE getBaseAddress() {
	return GetModuleHandle(NULL);
}

DWORD64* trace_pointer(memory_ptr* hack) {

	DWORD64* location = (DWORD64*)((DWORD64)getBaseAddress() + (DWORD64)hack->base_address);
	for (int i = 0; i < hack->total_offsets; i++) 
	{
		location = (DWORD64*)(*location + (int)hack->offsets[i]);
	}
	return location;
}

void init_pointers() {
	player_resource_hack = (player_resource*)(trace_pointer(&player_resource_hack_ptr));
	money_resource_hack = (money_resource*)(trace_pointer(&money_hack_ptr));
	ammo_resource_hack = (ammo_resource*)(trace_pointer(&ammo_resource_hack_ptr));
}

void GODMODE() {
	player_resource_hack->HP = (float)MAX_HP;
	player_resource_hack->ARMOUR = (float)MAX_ARMOUR;
}

void ARMED() {
	ammo_resource_hack->AMMO = (int)MAX_AMMO;
	ammo_resource_hack->MAG = (int)MAX_MAG;
}

void IHAVETHEMONEYSONNY() {
	money_resource_hack->MONEY = (long int)MAX_MONEY;
}

DWORD WINAPI MainThread(LPVOID param) {
	while (true) {
		if (GetAsyncKeyState(0xC0) & 1) {  //enables the goodstuff.. godmode, money
				init_pointers();
				Beep(1000, 500);
		}
		if (GetAsyncKeyState(0x31) & 1) {  // triggers health refill via key combo.. redundant but mainly used to fix vehicles..
			
			const int max_input = 16;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = A;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = A;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = S;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = S;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = P;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = P;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = I;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = I;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = R;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = R;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = I;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = I;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = N;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = N;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = E;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = E;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(0x32) & 1) {  //LeaveMeAlone Cheat! very helpful when you want things to cooldown..

			const int max_input = 24;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = L;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = L;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = E;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = E;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = A;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = A;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = V;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = V;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = E;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = E;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = M;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = M;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = E;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = E;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = A;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = A;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			in[16].type = INPUT_KEYBOARD;
			in[16].ki.wVk = L;

			in[17].type = INPUT_KEYBOARD;
			in[17].ki.wVk = L;
			in[17].ki.dwFlags = KEYEVENTF_KEYUP;

			in[18].type = INPUT_KEYBOARD;
			in[18].ki.wVk = O;

			in[19].type = INPUT_KEYBOARD;
			in[19].ki.wVk = O;
			in[19].ki.dwFlags = KEYEVENTF_KEYUP;

			in[20].type = INPUT_KEYBOARD;
			in[20].ki.wVk = N;

			in[21].type = INPUT_KEYBOARD;
			in[21].ki.wVk = N;
			in[21].ki.dwFlags = KEYEVENTF_KEYUP;

			in[22].type = INPUT_KEYBOARD;
			in[22].ki.wVk = E;

			in[23].type = INPUT_KEYBOARD;
			in[23].ki.wVk = E;
			in[23].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(0x33) & 1) {  //THUGSTOOLS

			const int max_input = 20;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = T;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = T;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = H;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = H;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = U;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = U;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = G;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = G;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = S;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = S;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = T;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = T;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = O;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = O;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = O;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = O;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			in[16].type = INPUT_KEYBOARD;
			in[16].ki.wVk = L;

			in[17].type = INPUT_KEYBOARD;
			in[17].ki.wVk = L;
			in[17].ki.dwFlags = KEYEVENTF_KEYUP;

			in[18].type = INPUT_KEYBOARD;
			in[18].ki.wVk = S;

			in[19].type = INPUT_KEYBOARD;
			in[19].ki.wVk = S;
			in[19].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(0x34) & 1) {  //NUTTERTOOLS

			const int max_input = 22;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = N;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = N;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = U;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = U;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = T;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = T;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = T;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = T;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = E;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = E;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = R;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = R;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = T;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = T;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = O;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = O;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			in[16].type = INPUT_KEYBOARD;
			in[16].ki.wVk = O;

			in[17].type = INPUT_KEYBOARD;
			in[17].ki.wVk = O;
			in[17].ki.dwFlags = KEYEVENTF_KEYUP;

			in[18].type = INPUT_KEYBOARD;
			in[18].ki.wVk = L;

			in[19].type = INPUT_KEYBOARD;
			in[19].ki.wVk = L;
			in[19].ki.dwFlags = KEYEVENTF_KEYUP;

			in[20].type = INPUT_KEYBOARD;
			in[20].ki.wVk = S;

			in[21].type = INPUT_KEYBOARD;
			in[21].ki.wVk = S;
			in[21].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(0x35) & 1) {  //PROFESSIONALTOOLS

			const int max_input = 34;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = P;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = P;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = R;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = R;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = O;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = O;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = F;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = F;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = E;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = E;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = S;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = S;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = S;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = S;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			in[14].type = INPUT_KEYBOARD;
			in[14].ki.wVk = I;

			in[15].type = INPUT_KEYBOARD;
			in[15].ki.wVk = I;
			in[15].ki.dwFlags = KEYEVENTF_KEYUP;

			in[16].type = INPUT_KEYBOARD;
			in[16].ki.wVk = O;

			in[17].type = INPUT_KEYBOARD;
			in[17].ki.wVk = O;
			in[17].ki.dwFlags = KEYEVENTF_KEYUP;

			in[18].type = INPUT_KEYBOARD;
			in[18].ki.wVk = N;

			in[19].type = INPUT_KEYBOARD;
			in[19].ki.wVk = N;
			in[19].ki.dwFlags = KEYEVENTF_KEYUP;

			in[20].type = INPUT_KEYBOARD;
			in[20].ki.wVk = A;

			in[21].type = INPUT_KEYBOARD;
			in[21].ki.wVk = A;
			in[21].ki.dwFlags = KEYEVENTF_KEYUP;

			in[22].type = INPUT_KEYBOARD;
			in[22].ki.wVk = L;

			in[23].type = INPUT_KEYBOARD;
			in[23].ki.wVk = L;
			in[23].ki.dwFlags = KEYEVENTF_KEYUP;

			in[24].type = INPUT_KEYBOARD;
			in[24].ki.wVk = T;

			in[25].type = INPUT_KEYBOARD;
			in[25].ki.wVk = T;
			in[25].ki.dwFlags = KEYEVENTF_KEYUP;

			in[26].type = INPUT_KEYBOARD;
			in[26].ki.wVk = O;

			in[27].type = INPUT_KEYBOARD;
			in[27].ki.wVk = O;
			in[27].ki.dwFlags = KEYEVENTF_KEYUP;

			in[28].type = INPUT_KEYBOARD;
			in[28].ki.wVk = O;

			in[29].type = INPUT_KEYBOARD;
			in[29].ki.wVk = O;
			in[29].ki.dwFlags = KEYEVENTF_KEYUP;

			in[30].type = INPUT_KEYBOARD;
			in[30].ki.wVk = L;

			in[31].type = INPUT_KEYBOARD;
			in[31].ki.wVk = L;
			in[31].ki.dwFlags = KEYEVENTF_KEYUP;

			in[32].type = INPUT_KEYBOARD;
			in[32].ki.wVk = S;

			in[33].type = INPUT_KEYBOARD;
			in[33].ki.wVk = S;
			in[33].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}
		if (GetAsyncKeyState(0x36) & 1) {  //BIGBANG cheat triggers a keycombo..

			const int max_input = 14;

			INPUT in[max_input] = {};
			ZeroMemory(in, sizeof(in));

			in[0].type = INPUT_KEYBOARD;
			in[0].ki.wVk = B;

			in[1].type = INPUT_KEYBOARD;
			in[1].ki.wVk = B;
			in[1].ki.dwFlags = KEYEVENTF_KEYUP;

			in[2].type = INPUT_KEYBOARD;
			in[2].ki.wVk = I;

			in[3].type = INPUT_KEYBOARD;
			in[3].ki.wVk = I;
			in[3].ki.dwFlags = KEYEVENTF_KEYUP;

			in[4].type = INPUT_KEYBOARD;
			in[4].ki.wVk = G;

			in[5].type = INPUT_KEYBOARD;
			in[5].ki.wVk = G;
			in[5].ki.dwFlags = KEYEVENTF_KEYUP;

			in[6].type = INPUT_KEYBOARD;
			in[6].ki.wVk = B;

			in[7].type = INPUT_KEYBOARD;
			in[7].ki.wVk = B;
			in[7].ki.dwFlags = KEYEVENTF_KEYUP;

			in[8].type = INPUT_KEYBOARD;
			in[8].ki.wVk = A;

			in[9].type = INPUT_KEYBOARD;
			in[9].ki.wVk = A;
			in[9].ki.dwFlags = KEYEVENTF_KEYUP;

			in[10].type = INPUT_KEYBOARD;
			in[10].ki.wVk = N;

			in[11].type = INPUT_KEYBOARD;
			in[11].ki.wVk = N;
			in[11].ki.dwFlags = KEYEVENTF_KEYUP;

			in[12].type = INPUT_KEYBOARD;
			in[12].ki.wVk = G;

			in[13].type = INPUT_KEYBOARD;
			in[13].ki.wVk = G;
			in[13].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uS = SendInput(max_input, in, sizeof(INPUT));

		}

		//these gets triggered when the pointers are valid via pressing `~
		if (player_resource_hack != NULL) {
			if (player_resource_hack->HP < MAX_HP && player_resource_hack->HP > 0) {
				GODMODE();
			}
			else if (player_resource_hack->ARMOUR < MAX_ARMOUR && player_resource_hack->HP > 0) {
				GODMODE();
			}
		}
		if (ammo_resource_hack != NULL) {
			if (ammo_resource_hack->AMMO < MAX_AMMO && ammo_resource_hack->AMMO > 0) {
				ARMED();
			}
			else if (ammo_resource_hack->MAG < MAX_MAG && ammo_resource_hack->AMMO > 0) {
				ARMED();
			}
		}
		if (money_resource_hack != NULL) {
			if (money_resource_hack->MONEY != MAX_MONEY){
				IHAVETHEMONEYSONNY();
			}
		}
	}
	return 0;
}

//DllMain entry and create MainThread
BOOL APIENTRY DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, MainThread, hInstDLL, 0, 0);
		Beep(1000, 750);
	}
	return true;
}

