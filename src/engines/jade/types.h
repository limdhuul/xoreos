/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Basic Jade Empire type definitions.
 */

#ifndef ENGINES_JADE_TYPES_H
#define ENGINES_JADE_TYPES_H

namespace Engines {

namespace Jade {

enum ObjectType {
	kObjectTypeInvalid         =  0,
	kObjectTypeContainer       =  1,
	kObjectTypeCreature        =  2,
	kObjectTypeDoor            =  3,
	kObjectTypeTrigger         =  4,
	kObjectTypePlayerCreature  =  5,
	kObjectTypeArea            =  7,
	kObjectTypeProjectile      =  8,
	kObjectTypePlaceable       =  9,
	kObjectTypeAreaOfEffect    = 10,
	kObjectTypeWaypoint        = 11,
	kObjectTypeSound           = 12,
	kObjectTypeCrowd           = 13,
	kObjectTypeMAX,

	kObjectTypeSelf         = 0x7FFE,
	kObjectTypeAll          = 0x7FFF
};

enum Script {
	kScriptOnHeartbeat           = 0,
	kScriptOnEnter               = 1,
	kScriptOnExit                = 2,
	kScriptOnUserdefined         = 3,
	kScriptOnDamage              = 4,
	kScriptOnDeath               = 5,
	kScriptOnDisarm              = 6,
	kScriptOnClick               = 7,
	kScriptOnTrapTriggered       = 8,
	kScriptOnOpen                = 9,
	kScriptOnClose               = 10,
	kScriptOnUnlock              = 11,
	kScriptOnFailToOpen          = 12,
	kScriptOnConversation        = 13,
	kScriptOnActivate            = 14,
	kScriptOnPerceptionAppeared  = 15,
	kScriptOnSpellCastAt         = 16,
	kScriptOnPhysicalAttacked    = 17,
	kScriptOnDisturbed           = 18,
	kScriptOnCombatEnd           = 19,
	kScriptOnSpawn               = 20,
	kScriptOnRested              = 21,
	kScriptOnBlocked             = 22,
	kScriptOnCreate              = 23,
	kScriptOnPerceptionVanished  = 24,
	kScriptOnUse                 = 25,
	kScriptOnDead                = 26,
	kScriptOnStateChange         = 27,
	kScriptOnSubCombatStart      = 28,
	kScriptOnSubCombatEnd        = 29,

	kScriptMAX
};

enum Animation {
	kAnimationWalk                         = 0,
	kAnimationWalkinj                      = 1,
	kAnimationWalkcom                      = 2,
	kAnimationWalkinjcom                   = 3,
	kAnimationRun                          = 4,
	kAnimationRuninj                       = 5,
	kAnimationRuncom                       = 6,
	kAnimationRuninjcom                    = 7,
	kAnimationPause                        = 8,
	kAnimationPausecom                     = 9,
	kAnimationPauseinj                     = 10,
	kAnimationPauseinjcom                  = 11,
	kAnimationSneak                        = 12,
	kAnimationSneakinj                     = 13,
	kAnimationSneakcom                     = 14,
	kAnimationSneakinjcom                  = 15,
	kAnimationWalkb                        = 16,
	kAnimationWalkbinj                     = 17,
	kAnimationWalkbcom                     = 18,
	kAnimationWalkbinjcom                  = 19,
	kAnimationWalkl                        = 20,
	kAnimationWalklinj                     = 21,
	kAnimationWalklcom                     = 22,
	kAnimationWalklinjcom                  = 23,
	kAnimationWalkr                        = 24,
	kAnimationWalkrinj                     = 25,
	kAnimationWalkrcom                     = 26,
	kAnimationWalkrinjcom                  = 27,
	kAnimationJog                          = 28,
	kAnimationJoginj                       = 29,
	kAnimationJogcom                       = 30,
	kAnimationJoginjcom                    = 31,
	kAnimationPauseDuplicateName           = 32,
	kAnimationPauseBored_1                 = 33,
	kAnimationPauseBored_2                 = 34,
	kAnimationPauseBored_3                 = 35,
	kAnimationBowMoreDemureForFemale       = 36,
	kAnimationBow_2                        = 37,
	kAnimationStandingTurnLeft             = 38,
	kAnimationStandingTurnRight            = 39,
	kAnimationPickUpItemGround             = 40,
	kAnimationPickUpItemTable              = 41,
	kAnimationJumpVertical                 = 42,
	kAnimationPauseEvil                    = 42,
	kAnimationMantle                       = 43,
	kAnimationPauseGood                    = 43,
	kAnimationClimbLadders                 = 44,
	kAnimationOpeningADoorDoubleDoor       = 45,
	kAnimationPush                         = 46,
	kAnimationOpeningAContainerOnTheGround = 47,
	kAnimationOpeningAContainerOnATable    = 48,
	kAnimationFlipASwitch                  = 49,
	kAnimationTurnAWheel                   = 50,
	kAnimationPullACord                    = 51,
	kAnimationPullingBackALever            = 52,
	kAnimationGiveItem                     = 53,
	kAnimationTakeItem                     = 54,
	kAnimationCough                        = 55,
	kAnimationSneeze                       = 56,
	kAnimationYawn                         = 57,
	kAnimationShoeAwayFlies                = 58,
	kAnimationStretch                      = 59,
	kAnimationScratchHead                  = 60,
	kAnimationScratchBelly                 = 61,
	kAnimationScratchAss                   = 62,
	kAnimationSleepy                       = 63,
	kAnimationObserving                    = 64,
	kAnimationPauseInjured                 = 65,
	kAnimationDrunkenPoisonedPause         = 66,
	kAnimationCreepForward                 = 67,
	kAnimationWalkForward                  = 68,
	kAnimationBackPeddle                   = 69,
	kAnimationJogForward                   = 70,
	kAnimationJogLeanLeft                  = 71,
	kAnimationJogLeanRight                 = 72,
	kAnimationDrunkenWalk                  = 73,
	kAnimationWalkInjured                  = 74,
	kAnimationWalkStairs                   = 75,
	kAnimationWalkingDiscussionL           = 76,
	kAnimationWalkingDiscussionR           = 77,
	kAnimationWalkFat                      = 78,
	kAnimationWalkScholar                  = 79,
	kAnimationWalkThief                    = 80,
	kAnimationWalkWArmsBack                = 81,
	kAnimationWalkWTightDress              = 82,
	kAnimationWalkBackBackPeddle           = 83,
	kAnimationHeavyLoadWalk                = 84,
	kAnimationCriminalWalk                 = 85,
	kAnimationStumbleTrip                  = 86,
	kAnimationRunForward_                  = 87,
	kAnimationRunInjured                   = 88,
	kAnimationRunLeanLeft                  = 89,
	kAnimationRunLeanRight                 = 90,
	kAnimationSittingDownOnChair           = 91,
	kAnimationSittingPause                 = 92,
	kAnimationStandingUpFromChair          = 93,
	kAnimationStandUpFromGround            = 94,
	kAnimationSittingOnGround              = 95,
	kAnimationSitOnGround                  = 96,
	kAnimationFaint                        = 97,
	kAnimationFaintPause                   = 98,
	kAnimationStandUpFromFaint             = 99,
	kAnimationLightTorch                   = 100,
	kAnimationHoldTorchLeft                = 101,
	kAnimationDrinkingFromMugWhileSitting  = 102,
	kAnimationEatingOnAChair               = 103,
	kAnimationEatingStandingUp             = 104,
	kAnimationGambling                     = 105,
	kAnimationGamblingWin                  = 106,
	kAnimationGamblingLose                 = 107,
	kAnimationGamblingObserve_1            = 108,
	kAnimationGamblingObserve_2            = 109,
	kAnimationDrunkenSleepingRaving        = 110,
	kAnimationPassingOutFaceFirstIntoFood  = 111,
	kAnimationWakingUpFromPassingOut       = 112,
	kAnimationCarryingAHeavyLoad           = 113,
	kAnimationWeighingItems                = 114,
	kAnimationHidingItemInSleeve           = 115,
	kAnimationFanning                      = 116,
	kAnimationFixingHair                   = 117,
	kAnimationKowtow                       = 118,
	kAnimationBackAwaySlavishly            = 119,
	kAnimationJuggling                     = 120,
	kAnimationBeckon                       = 121,
	kAnimationExclamationOfDismay          = 122,
	kAnimationFishing                      = 123,
	kAnimationTreatingInjury               = 124,
	kAnimationFlinchFromPain               = 125,
	kAnimationPlayingCricketGame           = 126,
	kAnimationPlayingCricketGameWin        = 127,
	kAnimationPlayingCricketGameLose       = 128,
	kAnimationPratfall                     = 129,
	kAnimationSpitTake                     = 130,
	kAnimationCelebration_1                = 131,
	kAnimationCelebration_2                = 132,
	kAnimationCelebration_3                = 133,
	kAnimationOrationRecitePoetry          = 134,
	kAnimationWriteDraw                    = 135,
	kAnimationSignName                     = 136,
	kAnimationCountingWithAbbacus          = 137,
	kAnimationUsingAnOfficialStamp         = 138,
	kAnimationSweeping                     = 139,
	kAnimationReligiousZealotPreaching     = 140,
	kAnimationMeditate                     = 141,
	kAnimationChant                        = 142,
	kAnimationSleeping                     = 143,
	kAnimationRingGong                     = 144,
	kAnimationPlayInstrument_1             = 145,
	kAnimationPlayInstrument_2             = 146,
	kAnimationFarming_1                    = 147,
	kAnimationFarming_2                    = 148,
	kAnimationWheelbarrowWalk              = 149,
	kAnimationChoppingHammering            = 150,
	kAnimationWhippingSlaves               = 151,
	kAnimationHunkerDownOnGround           = 152,
	kAnimationHunkerPause                  = 153,
	kAnimationStandFromHunker              = 154,
	kAnimationCookWithWok                  = 155,
	kAnimationFemaleDance                  = 156,
	kAnimationHookerBeckon                 = 157,
	kAnimationNormalTalkingGeneric         = 158,
	kAnimationNormalTalkingA               = 159,
	kAnimationNormalTalkingB               = 160,
	kAnimationAngrilyMakingAPointGeneric   = 161,
	kAnimationAngrilyMakingAPointA         = 162,
	kAnimationAngrilyMakingAPointB         = 163,
	kAnimationPleadingTalkingGeneric       = 164,
	kAnimationPleadingTalkingA             = 165,
	kAnimationPleadingTalkingB             = 166,
	kAnimationSadlyTalkingGenerc           = 167,
	kAnimationSadlyTalkingA                = 168,
	kAnimationLaughing                     = 169,
	kAnimationGreeting                     = 170,
	kAnimationFlirting                     = 171,
	kAnimationWaving                       = 172,
	kAnimationWaveBye                      = 173,
	kAnimationFawning                      = 174,
	kAnimationCringing                     = 175,
	kAnimationHorror                       = 176,
	kAnimationWhispering                   = 177,
	kAnimationTaunting                     = 178,
	kAnimationShrug                        = 179,
	kAnimationBribing                      = 180,
	kAnimationGossiping                    = 181,
	kAnimationSternIssuingOrder            = 182,
	kAnimationBegging                      = 183,
	kAnimationLaugh                        = 184,
	kAnimationDrunkenLaugh                 = 185,
	kAnimationListen                       = 186,
	kAnimationSlapRefuseSuitor             = 187,
	kAnimationSlapped                      = 188,
	kAnimationGirlishGiggle                = 189,
	kAnimationChud3Death                   = 248,
	kAnimationStayFainted                  = 250,
	kAnimationFlyAway                      = 261,
	kAnimationLand                         = 262,
	kAnimationLandB                        = 263,
	kAnimationStopHoldTorchLeft            = 268,
	kAnimationKata_1                       = 272,
	kAnimationKata_2                       = 273,
	kAnimationKata_3                       = 274,
	kAnimationBurningAction                = 304,
	kAnimationKneelToMeditate              = 288,
	kAnimationStandFromMeditate            = 289,
	kAnimationChantDown                    = 290,
	kAnimationChantToKneel                 = 291,
	kAnimationDeadBack1Perm                = 292,
	kAnimationDeadFront1Perm               = 293,
	kAnimationDeadFront2Perm               = 294,
	kAnimationKnockedDownFrontPerm         = 295,
	kAnimationKnockedDownBackPerm          = 296,
	kAnimationKnockedDownFrontCough        = 297,
	kAnimationKnockedDownBackCough         = 298,
	kAnimationGamblingDoOnce               = 299,
	kAnimationDeadBack2Loop                = 300,
	kAnimationSearchLoopKneel              = 301,
	kAnimationSearchToStand                = 302,
	kAnimationDustOffFromCombatReady       = 303,
	kAnimationBurningActionLoop            = 304,
	kAnimationPainDoOnce                   = 305,
	kAnimationLookRight                    = 306,
	kAnimationLookRightLoop                = 307,
	kAnimationLookRightToIdle              = 308,
	kAnimationLookLeft                     = 309,
	kAnimationLookLeftLoop                 = 310,
	kAnimationLookLeftToIdle               = 311,
	kAnimationRunningTurn                  = 312,
	kAnimationResetpause                   = 313,
	kAnimationCombatTurnLeft               = 314,
	kAnimationCombatTurnRight              = 315,
	kAnimationBurningDoOnce                = 316,
	kAnimationBackflip                     = 317,
	kAnimationPausetorun180                = 318,
	kAnimationEvilSmileDoOnce              = 319,
	kAnimationKneelDieDoOnce               = 320,
	kAnimationPauseArmsBehindBack          = 321,
	kAnimationGenderfreeVictory            = 322,
	kAnimationDamageHiFront                = 323,
	kAnimationDamageHiLeft                 = 324,
	kAnimationStunDoOnce                   = 325,
	kAnimationMeditatePermKneel            = 326,
	kAnimationSummonLoop                   = 327,
	kAnimationSummonStart                  = 328,
	kAnimationSearchToMagic                = 329,
	kAnimationProgrammerdefaultspeak       = 330,
	kAnimationProgrammerdefaultlisten      = 331,
	kAnimationPointForward                 = 332,
	kAnimationPointRight                   = 333,
	kAnimationPointLeft                    = 334,
	kAnimationBinding                      = 335
};

} // End of namespace Jade

} // End of namespace Engines

#endif /* ENGINES_JADE_TYPES_H */