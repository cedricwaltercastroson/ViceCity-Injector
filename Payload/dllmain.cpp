#pragma warning(disable: 4200)

// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

float MAX_HP = 200.0f;
float MAX_ARMOR = 200.0f;
signed long int MAX_MONEY = 2147483647;
int NEVERWANTED = 0;
int MAX_AMMO = 9999;

struct player_resource {
	float HP;
	float ARMOR;
};

struct money_resource {
	signed long int MONEY;
};

struct stamina_resource {
	bool STAMINA;
};

struct wantedlevel_resource {
	int WANTEDLEVEL;
};

struct pistol_resource {
	int PISTOL;
};

struct pistol_bullets_resource {
	int PISTOL_BULLETS;
};

struct smg_resource {
	int SMG;
};

struct smg_bullets_resource {
	int SMG_BULLETS;
};

struct ar_resource {
	int AR;
};

struct ar_bullets_resource {
	int AR_BULLETS;
};

struct shotgun_resource {
	int SHOTGUN;
};

struct sniper_resource {
	int SNIPER;
};

struct hweapon_resource {
	int HWEAPON;
};

struct hweapon_bullets_resource {
	int HWEAPON_BULLETS;
};

struct memory_ptr {
	DWORD64 base_address;
	int total_offsets;
	int offsets[];
};

memory_ptr player_resource_hack_ptr = {
		0x4D6EC30,
			1,
	{0x4DC}
};

memory_ptr money_hack_ptr = {
		0x4D6ED00,
			0,
	{ 0x0 }
};

memory_ptr stamina_hack_ptr = {
		0x4D6EDA4,
			0,
	{ 0x0 }
};

memory_ptr wantedlevel_hack_ptr = {
		0x4D6EC30,
			2,
	{ 0x8E0, 0x20 }
};

memory_ptr pistol_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x64C }
};

memory_ptr pistol_bullets_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x648 }
};

memory_ptr smg_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x68C }
};

memory_ptr smg_bullets_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x688 }
};

memory_ptr ar_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x6AC }
};

memory_ptr ar_bullets_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x6A8 }
};

memory_ptr shotgun_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x66C }
};

memory_ptr sniper_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x6EC }
};

memory_ptr hweapon_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x6CC }
};

memory_ptr hweapon_bullets_hack_ptr = {
		0x4D6EC30,
			1,
	{ 0x6C8 }
};

//pointer to resource struct
player_resource* player_resource_hack;
money_resource* money_resource_hack;
stamina_resource* stamina_resource_hack;
wantedlevel_resource* wantedlevel_hack;
pistol_resource* pistol_resource_hack;
pistol_bullets_resource* pistol_bullets_resource_hack;
smg_resource* smg_resource_hack;
smg_bullets_resource* smg_bullets_resource_hack;
ar_resource* ar_resource_hack;
ar_bullets_resource* ar_bullets_resource_hack;
shotgun_resource* shotgun_resource_hack;
sniper_resource* sniper_resource_hack;
hweapon_resource* hweapon_resource_hack;
hweapon_bullets_resource* hweapon_bullets_resource_hack;

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
	stamina_resource_hack = (stamina_resource*)(trace_pointer(&stamina_hack_ptr));
	wantedlevel_hack = (wantedlevel_resource*)(trace_pointer(&wantedlevel_hack_ptr));
	pistol_resource_hack = (pistol_resource*)(trace_pointer(&pistol_hack_ptr));
	pistol_bullets_resource_hack = (pistol_bullets_resource*)(trace_pointer(&pistol_bullets_hack_ptr));
	smg_resource_hack = (smg_resource*)(trace_pointer(&smg_hack_ptr));
	smg_bullets_resource_hack = (smg_bullets_resource*)(trace_pointer(&smg_bullets_hack_ptr));
	ar_resource_hack = (ar_resource*)(trace_pointer(&ar_hack_ptr));
	ar_bullets_resource_hack = (ar_bullets_resource*)(trace_pointer(&ar_bullets_hack_ptr));
	shotgun_resource_hack = (shotgun_resource*)(trace_pointer(&shotgun_hack_ptr));
	sniper_resource_hack = (sniper_resource*)(trace_pointer(&sniper_hack_ptr));
	hweapon_resource_hack = (hweapon_resource*)(trace_pointer(&hweapon_hack_ptr));
	hweapon_bullets_resource_hack = (hweapon_bullets_resource*)(trace_pointer(&hweapon_bullets_hack_ptr));
}

void GODMODE() {
	player_resource_hack->HP = (float)MAX_HP;
	player_resource_hack->ARMOR = (float)MAX_ARMOR;
	stamina_resource_hack->STAMINA = (bool)1;
	wantedlevel_hack->WANTEDLEVEL = (int)NEVERWANTED;
}

void PISTOL() {
	pistol_resource_hack->PISTOL = (int)MAX_AMMO;
	pistol_bullets_resource_hack->PISTOL_BULLETS = (int)MAX_AMMO;
}

void SMG() {
	smg_resource_hack->SMG = (int)MAX_AMMO;
	smg_bullets_resource_hack->SMG_BULLETS = (int)MAX_AMMO;
}

void AR() {
	ar_resource_hack->AR = (int)MAX_AMMO;
	ar_bullets_resource_hack->AR_BULLETS = (int)MAX_AMMO;
}

void SHOTGUN() {
	shotgun_resource_hack->SHOTGUN = (int)MAX_AMMO;
}

void SNIPER() {
	sniper_resource_hack->SNIPER = (int)MAX_AMMO;
}

void HWEAPON() {
	hweapon_resource_hack->HWEAPON = (int)MAX_AMMO;
	hweapon_bullets_resource_hack->HWEAPON_BULLETS = (int)MAX_AMMO;
}

void IHAVETHEMONEYSONNY() {
	money_resource_hack->MONEY = (long int)MAX_MONEY;
}

void TriggerCheat(const char* cheatCode) {
	size_t arraySize = strlen(cheatCode);
	const size_t max_input = arraySize * 2;

	INPUT* in = (INPUT*)calloc(max_input, sizeof(INPUT));

	ZeroMemory(in, max_input * sizeof(INPUT));

	for (size_t i = 0; i < arraySize; ++i) {
		in[i * 2].type = INPUT_KEYBOARD;
		in[i * 2].ki.wVk = (WORD)cheatCode[i];

		in[i * 2 + 1].type = INPUT_KEYBOARD;
		in[i * 2 + 1].ki.wVk = (WORD)cheatCode[i];
		in[i * 2 + 1].ki.dwFlags = KEYEVENTF_KEYUP;
	}

	UINT uS = SendInput(max_input, in, sizeof(INPUT));

	free(in);
}

DWORD WINAPI MainThread(LPVOID param) {
	while (true) {
		if (GetAsyncKeyState(0xC0) & 1) {  //enables the goodstuff.. godmode, money
				init_pointers();
				Beep(1000, 500);
		}

		if (GetAsyncKeyState(0x31) & 1) { // Trigger for first cheat
			const char* cheat1 = "ASPIRINE";
			TriggerCheat(cheat1);
		}

		if (GetAsyncKeyState(0x32) & 1) { // Trigger for second cheat
			const char* cheat2 = "LEAVEMEALONE";
			TriggerCheat(cheat2);
		}

		if (GetAsyncKeyState(0x33) & 1) { // Trigger for third cheat
			const char* cheat3 = "THUGSTOOLS";
			TriggerCheat(cheat3);
		}

		if (GetAsyncKeyState(0x34) & 1) { // Trigger for forth cheat
			const char* cheat4 = "PROFESSIONALTOOLS";
			TriggerCheat(cheat4);
		}

		if (GetAsyncKeyState(0x35) & 1) { // Trigger for fifth cheat
			const char* cheat5 = "NUTTERTOOLS";
			TriggerCheat(cheat5);
		}

		if (GetAsyncKeyState(0x36) & 1) { // Trigger for sixth cheat
			const char* cheat6 = "BIGBANG";
			TriggerCheat(cheat6);
		}

		//these gets triggered when the pointers are valid via pressing `~
		if (player_resource_hack != NULL) {
			if (player_resource_hack->HP != NULL) {
				if (player_resource_hack->HP < MAX_HP || player_resource_hack->ARMOR < MAX_ARMOR || wantedlevel_hack->WANTEDLEVEL > NEVERWANTED ) {
					GODMODE();
				}
			}
		}

		if (pistol_resource_hack != NULL) {
			if (pistol_resource_hack->PISTOL < MAX_AMMO || pistol_bullets_resource_hack->PISTOL_BULLETS < MAX_AMMO) {
				PISTOL();
			}
		}

		if (smg_resource_hack != NULL) {
			if (smg_resource_hack->SMG < MAX_AMMO || smg_bullets_resource_hack->SMG_BULLETS < MAX_AMMO) {
				SMG();
			}
		}

		if (ar_resource_hack != NULL) {
			if (ar_resource_hack->AR < MAX_AMMO || ar_bullets_resource_hack->AR_BULLETS < MAX_AMMO) {
				AR();
			}
		}

		if (shotgun_resource_hack != NULL) {
			if (shotgun_resource_hack->SHOTGUN < MAX_AMMO) {
				SHOTGUN();
			}
		}

		if (sniper_resource_hack != NULL) {
			if (sniper_resource_hack->SNIPER < MAX_AMMO) {
				SNIPER();
			}
		}

		if (hweapon_resource_hack != NULL) {
			if (hweapon_resource_hack->HWEAPON < MAX_AMMO || hweapon_bullets_resource_hack->HWEAPON_BULLETS < MAX_AMMO) {
				HWEAPON();
			}
		}

		if (money_resource_hack != NULL) {
			if (money_resource_hack->MONEY < MAX_MONEY){
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

