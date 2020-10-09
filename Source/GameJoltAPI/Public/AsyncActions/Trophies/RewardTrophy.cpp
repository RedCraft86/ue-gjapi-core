// Copyright by Free2Play-Entertainment (2020)


#include "RewardTrophy.h"

URewardTrophy* URewardTrophy::RewardTrophy(const int32 ID)
{
    URewardTrophy* TrophyNode = NewObject<URewardTrophy>();
    TrophyNode->TrophyID = ID;
    return TrophyNode;
}

void URewardTrophy::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("/trophies/add-achieved/?trophy_id=" + FString::FromInt(TrophyID))));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URewardTrophy::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast();
}