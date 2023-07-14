#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{
	//하나의 요소에 접근
	{
		FVector vector(0.0, 1.0, 2.0);
		vector.X = 5.0;

		TestEqual(TEXT("FVector"), vector, FVector(5.0, 1.0, 2.0));
	}
	
	//벡터 연산
	{
		FVector vector1(0.0, 1.0, 2.0);
		FVector vector2(1.0, 1.0, 1.0);

		TestEqual(TEXT("FVector +"), vector1 + vector2, FVector(1.0, 2.0, 3.0));
	}

	//벡터 정규화
	{
		FVector vector(0.0, 5.0, 0.0);
		vector.Normalize();

		TestEqual(TEXT("FVector Normalized"), vector, FVector(0.0, 1.0, 0.0));
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaRotatorTest, "Beluga.Rotator", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaRotatorTest::RunTest(const FString& Parameters)
{
	// yaw, pitch, roll
	FRotator rotator(0.1, 0.1, 0.1);

	rotator.Add(1.0, 1.0, 1.0);
	//근사치 equal 판별어려움


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMatrixTest, "Beluga.Matrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMatrixTest::RunTest(const FString& Parameters)
{
	//FMatrix 초기화
	FVector vec(0.1, 0.1, 0.1);
	FMatrix mat(vec, vec, vec, vec);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTransformTest, "Beluga.Transform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTransformTest::RunTest(const FString& Parameters)
{
	//FTransform 초기화
	FRotator rot(0.1, 0.1, 0.1);
	FVector vec(0.1, 0.1, 0.1);
	FTransform trans(rot, vec, vec);
	return true;
}