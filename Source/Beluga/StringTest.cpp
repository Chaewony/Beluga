#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

//FString 사용해보기
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// 생성, 대입
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

	//길이 구하기 
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
		str.Shrink();// 메모리 사이즈 max로 확인

		int32 shrinked = str.GetAllocatedSize();
		TestEqual(TEXT("Shrink"), reserved, shrinked);
	}

	// 대문자로 변환, 소문자로 변환
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
		FString out = str.Left(2); //왼쪽에서 2개까지
		TestEqual(TEXT("Left"), out, TEXT("as"));
	}
	// Mid
	{
		//Returns the substring from Start position to the end
		FString str(TEXT("asdfghjk"));
		FString out = str.Mid(2); //앞에서 2개 짜르고 싹다 붙여
		TestEqual(TEXT("Mid"), out, TEXT("dfghjk"));
	}
	// Mid2
	{
		//Returns the substring from Start position to the end
		FString str(TEXT("asdfghjk"));
		FString out = str.Mid(4);//앞에서 4개 짜르고 중간은 싹다 붙여
		TestEqual(TEXT("Mid2"), out, TEXT("ghjk"));
	}
	// Right
	{
		//Returns the string to the right of the specified location, counting back from the right (end of the word)
		FString str(TEXT("asdfghjk"));
		FString out = str.Right(2); //오른쪽에서 2개까지
		check(out == TEXT("jk"));
	}

	return true;
}

//FName 사용해보기
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	 //Compare
	{
		FName name = FName(TEXT("TestFName"));
		TestTrue(TEXT("Compare"), name.Compare("TestFName") == 0);
	}

	//연산자 < 
	{
		FName name1 = FName(TEXT("abcd"));
		FName name2 = FName(TEXT("efgh"));
		TestTrue(TEXT("Compare"), name1<name2);
	}

	return true;
}

//FText 사용해보기
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTextTest, "Beluga.Text", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTextTest::RunTest(const FString& Parameters)
{
	{
		FText helloWorld = NSLOCTEXT("MyNamespace", "HelloWorld", "Hello World!");
		#define LOCTEXT_NAMESPACE "MyNamespace"
		FText goodbyeWorld = LOCTEXT("GoodbyeWorld", "Goodbye World!");
		#undef LOCTEXT_NAMESPACE
	}
	return true;
}