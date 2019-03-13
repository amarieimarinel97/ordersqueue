#pragma once
#include "Menu.h"

//////////////////////////////////////////////////

class Write : public Operation
{
public:
	Write(char *name);
	void ExecuteOperation(void);
};

class Read : public Operation
{
public: 
	Read(char *name);
	void ExecuteOperation(void);
};

class FileWrite : public Operation
{
public:
	FileWrite(char *name);
	void ExecuteOperation(void);
};

class FileRead : public Operation
{
public: FileRead(char *name);
		void ExecuteOperation(void);
};

class CheckFile : public Operation
{
public:
	CheckFile(char *name);
	void ExecuteOperation(void);
};

class EraseFile : public Operation
{
public:
	EraseFile(char *name);
	void ExecuteOperation(void);
};