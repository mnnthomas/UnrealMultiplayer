// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Blue, FString::Printf(TEXT("Players in Game : %d"), NumberOfPlayers));

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Player Joined : %s"), *NewPlayer->GetName()));

	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Blue, FString::Printf(TEXT("Players in Game : %d"), NumberOfPlayers-1));

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Player Joined : %s"), *Exiting->GetName()));
	}
}
