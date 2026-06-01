#pragma once
#include <string>
/**
* This class is responsible for opening a file dialog and returning
**/

class FileHandler {
public:
	static std::wstring GetFilePathFromDialog();
};