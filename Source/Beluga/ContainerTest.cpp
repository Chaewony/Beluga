#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

//TArray 사용해보기
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaArrayTest, "Beluga.Array", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
bool FBelugaArrayTest::RunTest(const FString& Parameters)
{
	{
		TArray<int32> arr = { 1, 2, 3 };
		arr.Add(4);
		TestEqual(TEXT("TArray Add"), arr, TArray<int32>{1, 2, 3, 4});
	}
	
	{
		TArray<int32> arr = { 1, 2, 3 };
		TestEqual(TEXT("TArray begin"), *arr.begin(), 1);
		TestEqual(TEXT("TArray end"), *arr.end(), 3);
	}

	{
		TArray<int32> arr = { 1, 2, 3 };
		arr.Insert(1, 1);
		TestEqual(TEXT("TArray Insert"), arr, TArray<int32>{1, 1, 2, 3});
	}

	return true;
}

//TMap 사용해보기
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMapTest, "Beluga.Map", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMapTest::RunTest(const FString& Parameters)
{
	{
		TMap<FName, FString> map = { {TEXT("A"), TEXT("Apple")}, { TEXT("B"), TEXT("Banana") }, { TEXT("C"), TEXT("Cherry") } };
		map.Add({ TEXT("D"), TEXT("Durian") });
		TestTrue(TEXT("TMap Contains"), map.Contains("D"));

		TestEqual(TEXT("TMap Num"), map.Num(), 4);

		FString* ptr = map.Find("C");
		TestEqual(TEXT("TMap Find"), *ptr, TEXT("Cherry"));
	}
	return true;
}

//TSet 사용해보기
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaSetTest, "Beluga.Set", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaSetTest::RunTest(const FString& Parameters)
{
	TSet<FName> set = { "Banana", "Grapefruit", "Pineapple" };

	set.Add("Pear");
	TestTrue(TEXT("TSet Num"), set.Num() == 4);

	set.Remove("Banana");
	TestTrue(TEXT("TSet begin"), *set.begin() == "Grapefruit");

	
	return true;
}