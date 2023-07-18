#include "DogCreature.h"

FString UDogCreature::CPP_Hello()
{
	return HelloMsg;
}

FName UDogCreature::CPP_GetName()
{
	return Name;
}

void UDogCreature::BOTH_Update_Implementation()
{
	HelloMsg = HelloMsg.ToUpper();
}