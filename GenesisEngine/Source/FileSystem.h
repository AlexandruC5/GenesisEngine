#pragma once

class MeshCollection;

#include <vector>
#include <string>

namespace FileSystem
{
	void Init();
	void CleanUp();

	void CreateLibraryDirectories();

	bool AddPath(const char* path_or_zip);
	bool Exists(const char* file);
	bool CreateDir(const char* dir);
	bool IsDirectory(const char* file);
	const char* GetWriteDir();
	void DiscoverFiles(const char* directory, std::vector<std::string>& file_list, std::vector<std::string>& dir_list);
	void GetAllFilesWithExtension(const char* directory, const char* extension, std::vector<std::string>& file_list);
	//PathNode GetAllFiles(const char* directory, std::vector<std::string>* filter_ext = nullptr, std::vector<std::string>* ignore_ext = nullptr);
	void GetRealDir(const char* path, std::string& output);
	std::string GetPathRelativeToAssets(const char* originalPath);

	bool HasExtension(const char* path);
	bool HasExtension(const char* path, std::string extension);
	bool HasExtension(const char* path, std::vector<std::string> extensions);

	std::string NormalizePath(const char* path);
	void SplitFilePath(const char* full_path, std::string* path, std::string* file = nullptr, std::string* extension = nullptr);

	// Open for Read/Write
	unsigned int Load(const char* path, const char* file, char** buffer);
	unsigned int Load(const char* file, char** buffer);

	bool DuplicateFile(const char* file, const char* dstFolder, std::string& relativePath);
	bool DuplicateFile(const char* srcFile, const char* dstFile);

	unsigned int Save(const char* file, const void* buffer, unsigned int size, bool append = false);
	bool Remove(const char* file);

	//uint64 GetLastModTime(const char* filename);
	std::string GetUniqueName(const char* path, const char* name);

	MeshCollection* LoadFBX(const char* path);
}


