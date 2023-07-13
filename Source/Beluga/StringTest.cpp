#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// ����, ����
	{
		FString strChar("char");
		FString strWChar(L"wchar");
		FString strTChar(TEXT("wchar"));

		strChar = "char";
		strWChar = "wchar";
		strTChar = TEXT("wchar");
	}

	// Printf
	{
		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
	}

	// Format
	{
		{
			FStringFormatNamedArguments NamedArgs;
			NamedArgs.Add(TEXT("First"), 123);
			NamedArgs.Add(TEXT("Second"), 1.0f);
			NamedArgs.Add(TEXT("Third"), TEXT("string"));

			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
		}

		{
			FStringFormatOrderedArguments OrderedArgs;
			OrderedArgs.Add(123);
			OrderedArgs.Add(1.0f);
			OrderedArgs.Add(TEXT("string"));

			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
		}
	}

	FString strApple(TEXT("Apple"));
	FString strBanana(TEXT("Banana"));

	// Operators
	{
		// []
		{
			TestEqual(TEXT("Operator []"), strApple[0], L'A');
		}

		// < >
		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
	}

	//���� ���ϱ� 
	{
		FString str(TEXT("str"));
		int32 LenStr = str.Len();
		TestTrue(TEXT("Length"), LenStr == 3);
	}

	// Replace
	{
		FString str(TEXT("asdf"));
		FString result = str.Replace(TEXT("sd"), TEXT("ds"));
		TestTrue(TEXT("Replace"), result == TEXT("adsf"));
	}

	// IsEmpty
	{
		FString str(TEXT("asdf"));
		TestTrue(TEXT("isEnmpty"), !str.IsEmpty());
	}

	// Shrink
	{
		FString str;
		str.Reserve(1000);

		int32 reserved = str.GetAllocatedSize();
		str.Shrink();// �޸� ������ max�� Ȯ��

		int32 shrinked = str.GetAllocatedSize();
		TestEqual(TEXT("Shrink"), reserved, shrinked);
	}

	// �빮�ڷ� ��ȯ, �ҹ��ڷ� ��ȯ
	{
		FString str0(TEXT("asdf"));
		FString out0 = str0.ToUpper();
		TestEqual(TEXT("Big"), out0, TEXT("ASDF"));

		FString str1(TEXT("ASDF"));
		FString out1 = str1.ToLower();
		TestEqual(TEXT("Small"), out1, TEXT("asdf"));
	}

	// Left
	{
		//Returns the left most given number of characters
		FString str(TEXT("asdfghjk"));
		FString out = str.Left(2); //���ʿ��� 2������
		TestEqual(TEXT("Left"), out, TEXT("as"));
	}
	// Mid
	{
		//Returns the substring from Start position to the end
		FString str(TEXT("asdfghjk"));
		FString out = str.Mid(2); //�տ��� 2�� ¥���� �ϴ� �ٿ�
		TestEqual(TEXT("Mid"), out, TEXT("dfghjk"));
	}
	// Mid2
	{
		//Returns the substring from Start position to the end
		FString str(TEXT("asdfghjk"));
		FString out = str.Mid(4);//�տ��� 4�� ¥���� �߰��� �ϴ� �ٿ�
		TestEqual(TEXT("Mid2"), out, TEXT("ghjk"));
	}
	// Right
	{
		//Returns the string to the right of the specified location, counting back from the right (end of the word)
		FString str(TEXT("asdfghjk"));
		FString out = str.Right(2); //�����ʿ��� 2������
		check(out == TEXT("jk"));
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	return true;
}
//void StringTest()
//{
//	//���� ���ϱ� 
//	{
//		FString str(TEXT("str"));
//		int32 LenStr = str.Len();
//		check(LenStr == 3);
//	}
//	
//	// ����
//		// char		"asdf"
//		// wchar	L"asdf"
//		// tchar	TEXT("asdf")
//
//	{
//		FString str0(L"wchar");
//		FString str1("char");
//		FString str2(TEXT("tchar"));
//	}
//
//
//	// ���� ������ = 
//
//	// Printf
//
//	// Format
//
//	// operator []
//
//	// ��Һ�
//
//	// TCHAR* ���
//	// operator*
//
//	// ���� ���ϱ�
//
//	// Replace
//	{
//		FString str(TEXT("asdf"));
//		FString result = str.Replace(TEXT("sd"), TEXT("ds"));
//		check(result == TEXT("adsf"));
//	}
//
//	// Insert
//
//	// clear
//
//	// Split
//
//	// IsEmpty
//	{
//		FString str(TEXT("asdf"));
//		check(!str.IsEmpty());
//	}
//
//	// Shrink
//	{
//		FString str(TEXT("Hello World!"));
//		str.Shrink();
//	}
//
//	// RemoveAt
//
//	// find �� �ε���
//
//	// Left
//	{
//		FString str(TEXT("asdfghjk"));
//		FString out = str.Left(4);
//		check(out == TEXT("asdf"));
//	}
//	// Mid
//	/*{
//		FString str(TEXT("asdfghjk"));
//		FString out = str.Mid(4);
//		check(out == TEXT("dfgh"));
//	}*/
//	// Right
//	{
//		FString str(TEXT("asdfghjk"));
//		FString out = str.Mid(4);
//		check(out == TEXT("ghjk"));
//	}
//
//	// �빮�ڷ� ��ȯ, �ҹ��ڷ� ��ȯ
//	{
//		FString str0(TEXT("asdf"));
//		FString out0 = str0.ToUpper();
//		check(out0 == TEXT("ASDF"));
//
//		FString str1(TEXT("ASDF"));
//		FString out1 = str1.ToLower();
//		check(out1 == TEXT("asdf"));
//	}
//}