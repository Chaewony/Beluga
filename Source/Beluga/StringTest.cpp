#include "BelugaMinimal.h"

void StringTest()
{
	//���� ���ϱ� 
	{
		FString str(TEXT("str"));
		int32 LenStr = str.Len();
		check(LenStr == 3);
	}
	
	// ����
		// char		"asdf"
		// wchar	L"asdf"
		// tchar	TEXT("asdf")

	{
		FString str0(L"wchar");
		FString str1("char");
		FString str2(TEXT("tchar"));
	}


	// ���� ������ = 

	// Printf

	// Format

	// operator []

	// ��Һ�

	// TCHAR* ���
	// operator*

	// ���� ���ϱ�

	// Replace
	{
		FString str(TEXT("asdf"));
		FString result = str.Replace(TEXT("sd"), TEXT("ds"));
		check(result == TEXT("adsf"));
	}

	// Insert

	// clear

	// Split

	// IsEmpty
	{
		FString str(TEXT("asdf"));
		check(!str.IsEmpty());
	}

	// Shrink
	{
		FString str(TEXT("Hello World!"));
		str.Shrink();
	}

	// RemoveAt

	// find �� �ε���

	// Left
	{
		FString str(TEXT("asdfghjk"));
		FString out = str.Left(4);
		check(out == TEXT("asdf"));
	}
	// Mid
	{
		FString str(TEXT("asdfghjk"));
		FString out = str.Mid(4);
		check(out == TEXT("dfgh"));
	}
	// Right
	{
		FString str(TEXT("asdfghjk"));
		FString out = str.Mid(4);
		check(out == TEXT("ghjk"));
	}

	// �빮�ڷ� ��ȯ, �ҹ��ڷ� ��ȯ
	{
		FString str0(TEXT("asdf"));
		FString out0 = str0.ToUpper();
		check(out0 == TEXT("ASDF"));

		FString str1(TEXT("ASDF"));
		FString out1 = str1.ToLower();
		check(out1 == TEXT("asdf"));
	}
}