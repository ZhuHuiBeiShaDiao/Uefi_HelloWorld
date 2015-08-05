#include <Uefi.h>
//build -p Nt32Pkg\Nt32Pkg.dsc
EFI_STATUS UefiMain(IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_STATUS Status;
	UINTN Index;
	EFI_INPUT_KEY Key;
	CHAR16 StrBuffer[3] = {0};
	SystemTable->BootServices->WaitForEvent(1,&SystemTable->ConIn->WaitForKey,&Index);
	//wait input
	Status = SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn,&Key);
	StrBuffer[0] = Key.UnicodeChar;
	StrBuffer[1] = '\n';
	SystemTable->ConOut->OutputString(SystemTable->ConOut,StrBuffer);
	return EFI_SUCCESS;
}