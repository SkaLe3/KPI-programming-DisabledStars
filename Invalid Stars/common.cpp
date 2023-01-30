#include "common.h"


// Texture names
std::string pop_cat = "pop_cat.png";
std::string backgroundTex = "MenuBackground.jpg";
std::string gameBGTex = "levels.jpg";
std::string titleTex = "Title.png";
std::string playTex = "Play.png";
std::string settingsTex = "Settings.png";
std::string settingsBGTex = "SettingsBackground.jpg";
std::string helpTex = "Help.png";
std::string musicPrevTex = "musicPrev.png";
std::string musicAtDoomsGateTex = "AtDoomsGate.png";
std::string musicRipAndTearTex = "RipAndTear.png";
std::string musicTheOnlyThingTex = "TheOnlyThing.png";
std::string musicNextTex = "musicNext.png";

std::string rulesTex = "rules.png";
std::string backTex = "back.png";
std::string musicOnTex = "switch_on.png";
std::string musicOffTex = "switch_off.png";

std::string failedTex = "failed.png";
std::string wonTex = "won.png";

// Click status
bool click = false;
// Music status
bool musicIsOn = true;
// number of selected track
int selectedMusic = 0;

// Array with songs names textures
std::string musName[3] = { musicAtDoomsGateTex, musicRipAndTearTex, musicTheOnlyThingTex };
// Array with songs file names
const char* musFile[3] = { "Audio/At_Dooms_Gate.mp3", "Audio/Rip_And_Tear.mp3", "Audio/The_Only_Thing_They_Fear_Is_You.mp3"};

// Array with contellations texture names
std::string constellationTex[12] = {
	"CancerTex.png",
	"PiscesTex.png",
	"AriesTex.png",
	"SagittariusTex.png",
	"VirgoTex.png",
	"GeminiTex.png",
	"LeoTex.png",
	"TaurusTex.png",
	"LibraTex.png",
	"AquariusTex.png",
	"ScorpioTex.png",
	"CapricornTex.png"
};
// Array with button names
std::string buttonsTex[48] = {
	"Capricorn.png", "Cancer.png", "Scorpio.png", "Libra.png",     //Cancer
	"Pisces.png", "Libra.png", "Gemini.png", "Aries.png",			//Pisces
	"Aquarius.png", "Aries.png", "Virgo.png", "Cancer.png",			//Aries
	"Leo.png", "Capricorn.png", "Scorpio.png", "Sagittarius.png",	//Sagittarius
	"Aquarius.png", "Aries.png", "Taurus.png", "Virgo.png",				//Virgo
	"Cancer.png", "Gemini.png", "Sagittarius.png", "Aquarius.png",		//Gemini
	"Libra.png", "Pisces.png", "Leo.png", "Capricorn.png",				//Leo
	"Taurus.png", "Cancer.png", "Virgo.png", "Scorpio.png",				//Taurus
	"Aquarius.png", "Libra.png", "Pisces.png", "Aries.png",				//Libra
	"Sagittarius.png", "Aquarius.png", "Leo.png", "Capricorn.png",		//Aquarius
	"Virgo.png", "Libra.png", "Scorpio.png", "Gemini.png",				//Scorpio
	"Pisces.png", "Aries.png", "Taurus.png", "Capricorn.png"			//Capricorn			
};
// Array with right answers
int answer[12] = { 2, 1, 2, 4, 4, 2, 3, 1, 2, 2, 3, 4 };