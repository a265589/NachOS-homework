/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"

#include "synchconsole.h"

void SysHalt()
{
	kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
	return op1 + op2;
}

#ifdef FILESYS_STUB
int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}
#endif

int Create(char *filename, int size) //MP4陳柏均修改的
{
	return kernel->fileSystem->CreateFile(filename, size);
}

//When you finish the function "OpenAFile", you can remove the comment below.

OpenFileId Open(char *name) //MP4陳柏均修改的
{
	return kernel->fileSystem->OpenAFile(name); // 調用filesys.h Chen 寫的函式內容
}

int Read(char *buffer, int size, OpenFileId id) //MP4陳柏均修改的
{
	return kernel->fileSystem->Read(buffer, size, id); // 調用filesys.h Zheng 寫的函式內容
}

int Write(char *buffer, int size, OpenFileId id) //MP4陳柏均修改的
{
	return kernel->fileSystem->Write(buffer, size, id); //調用filesys.h Chen 寫的函式內容
}

int CloseFile(OpenFileId id) //MP4陳柏均修改的
{
	return kernel->fileSystem->Close(id); //調用filesys.h Chen 寫的函式內容
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
