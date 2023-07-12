#include "BelugaMinimal.h"

void StringTest()
{
	//길이 구하기 
	{
		FString str(TEXT("str"));
		int32 LenStr = str.Len();
		check(LenStr == 3);
	}
	
	// 생성
		// char		"asdf"
		// wchar	L"asdf"
		// tchar	TEXT("asdf")

	{
		FString str0(L"wchar");
		FString str1("char");
		FString str2(TEXT("tchar"));
	}


	// 대입 연산자 = 

	// Printf

	// Format

	// operator []

	// 대소비교

	// TCHAR* 얻기
	// operator*

	// 길이 구하기

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

	// find 로 인덱스

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

	// 대문자로 변환, 소문자로 변환
	{
		FString str0(TEXT("asdf"));
		FString out0 = str0.ToUpper();
		check(out0 == TEXT("ASDF"));

		FString str1(TEXT("ASDF"));
		FString out1 = str1.ToLower();
		check(out1 == TEXT("asdf"));
	}
}