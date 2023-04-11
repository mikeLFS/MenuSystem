// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UMultiplayerSessionsSubsystem();

	//
	// To handle session functionality. The menu class will call these.
	//
	void CreateSession(int32 NumPublicConnection, FString MatchType);
	void FindSession(int32 MaxSearchResult);
	void JoinSession(const FOnlineSessionSearchResult& SearchResult);
	void DestroySession();
	void StartSession();

protected:
	//
	//Internal Callbacks for the delegate we will add to the online session Interface delegate list.
	//This dont need to be called outside the class.
	//
	void CreateSessionComplete(FName SessionName, bool bWasSuccessfull);
	void FindSessionsComplete(bool bWasSuccessfull);
	void JoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void DestroySessionComplete(FName SessionName, bool bWasSuccessfull);
	void StartSessionComplete(FName SessionName, bool bWasSuccessfull);

private:
	IOnlineSessionPtr SessionInterface;

	//
	//To add to the online Session Interface Delegate List.
	// We will bind our MultiplayerSessionSubsystem internal callback to these.
	//
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;
};
