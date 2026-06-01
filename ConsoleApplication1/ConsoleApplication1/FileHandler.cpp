#include "filehandler.h"
#include <windows.h>
#include <commdlg.h>

std::wstring FileHandler::GetFilePathFromDialog() {
    OPENFILENAME ofn;
    wchar_t fileName[MAX_PATH] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"Video Files\0*.mp4;*.avi;*.mkv\0All Files\0*.*\0";
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn))
    {
        return std::wstring(ofn.lpstrFile);
    }

    return L"";
}