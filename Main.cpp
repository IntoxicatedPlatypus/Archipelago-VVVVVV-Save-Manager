#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

std::wstring StringToWString(const std::string& str) {
	std::wstring wstr;
	size_t size;
	wstr.resize(str.length());
	mbstowcs_s(&size, &wstr[0], wstr.size() + 1, str.c_str(), str.size());
	return wstr;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	std::wstring dir = std::filesystem::current_path().wstring();

	std::wstring profile = StringToWString(argv[0]);

	if (profile.find_last_of('/') != std::string::npos)
		profile = profile.substr(profile.find_last_of('/') + 1);

	if (profile.find_last_of('\\') != std::string::npos)
		profile = profile.substr(profile.find_last_of('\\') + 1);

	profile = profile.substr(0, profile.length() - 4);


	std::filesystem::create_directory(dir + L"\\" + profile);


	std::wifstream conf("config.txt");

	std::wstring ip;
	std::getline(conf, ip);

	std::wstring pwd;
	bool pwdLocked = (bool)std::getline(conf, pwd);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	std::wstring cmdLine = L"\"" + dir + L"\\VVVVVV\\VVVVVV.exe\" -basedir \"" + dir + L"\\" + profile + L"\" -v6ap_name \"" + profile + L"\" -v6ap_ip " + ip;
	if (pwdLocked)
		cmdLine += L" -v6ap_passwd \"" + pwd + L"\"";

	wchar_t waa[1024];
	wcscpy_s(waa, cmdLine.c_str());

	CreateProcess(nullptr,
		waa,
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}