#pragma once
#include <windows.h>

static HWND g_hwnd = nullptr;

extern "C" __declspec(dllexport)
void SetRenderWindow(HWND hwnd)
{
    g_hwnd = hwnd;
}