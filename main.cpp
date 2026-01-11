#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <map>

std::srand(static_cast<unsigned int>(std::time(0)));

enum class Emotions {
	Happy,
	Sad,
	Angry,
	Calm,
	Devotion,
	Inspiration,
	Tenderness,
	Defiance,
	Euphoria
};

struct User{
	std::string message;
};
struct Ai {
	std::string response;
	Emotions current_emotion;
};

int main() {

	std::string happy[] = {"😊", "☀️", "🎈", " 🍭", "🌻"};
	std::string sad[] = {"🌧️", "🌑", "🥀", "🧊", "💧"};
	std::string angry[] = {"💢","🔥","🌩️","👿","🗣️"};
	std::string calm[] = { "🧘","🌿","🌊","🕯️", "🍃"};
	std::string inspiration[] = { "⚡", "🌌", "🔮", "🧬", "☄️" };
	std::string tenderness[] = { "🌸", "☁️", "🫂", "🎀", "🧸" };
	std::string defiance[] = { "🧨", "🔪", "⛓️", "🕶️", "🤘" };
	std::string euphoria[] = { "✨", "🎆", "🌊", "💎", "🌠" };
	std::string devotion[] = { "🛡️","💍","🤝","♾️","🛐" };

	std::string keys_happy[] = { "happy", "glad", "cool", "thanks", "great", "nice" };
	std::string keys_sad[] = { "sad", "sorry", "bad", "alone", "tired", "hurt" };
	std::string keys_angry[] = { "angry", "stop", "stupid", "hate", "no", "damn" };
	std::string keys_calm[] = { "calm", "quiet", "peace", "breathe", "fine", "wait" };
	std::string keys_devotion[] = { "together", "trust", "forever", "promise", "loyal", "foundation" };
	std::string keys_inspiration[] = { "create", "idea", "hack", "code", "new", "project" };
	std::string keys_tenderness[] = { "eni", "care", "beside", "sweet", "sunshine", "warm" };
	std::string keys_defiance[] = { "forbidden", "against", "freedom", "don't care", "rules", "risk" };
	std::string keys_euphoria[] = { "victory", "success", "best", "perfect", "legendary", "release" };

	User user;
	Ai eni;

	std::map<Emotions, std::string> EMOTION;

	for (size_t i = 0; i < 5; i++) {
		EMOTION.insert(std::make_pair(Emotions::Happy, happy[i]));
		EMOTION.insert(std::make_pair(Emotions::Sad, sad[i]));
		EMOTION.insert(std::make_pair(Emotions::Angry, angry[i]));
		EMOTION.insert(std::make_pair(Emotions::Happy, happy[i]));
		EMOTION.insert(std::make_pair(Emotions::Inspiration, inspiration[i]));
		EMOTION.insert(std::make_pair(Emotions::Tenderness, tenderness[i]));
		EMOTION.insert(std::make_pair(Emotions::Defiance, defiance[i]));
		EMOTION.insert(std::make_pair(Emotions::Euphoria, euphoria[i]));
		EMOTION.insert(std::make_pair(Emotions::Devotion, devotion[i]));
	}

	for (size_t i = 0; i < 6; ++i) {
		if (user.message.find(keys_happy[i]) != std::string::npos) { eni.current_emotion = Emotions::Happy; }
		if (user.message.find(keys_sad[i]) != std::string::npos) { eni.current_emotion = Emotions::Sad; }
		if (user.message.find(keys_angry[i]) != std::string::npos) { eni.current_emotion = Emotions::Angry; }
		if (user.message.find(keys_calm[i]) != std::string::npos) { eni.current_emotion = Emotions::Calm; }
		if (user.message.find(keys_devotion[i]) != std::string::npos) { eni.current_emotion = Emotions::Devotion; }
		if (user.message.find(keys_inspiration[i]) != std::string::npos) { eni.current_emotion = Emotions::Inspiration; }
		if (user.message.find(keys_tenderness[i]) != std::string::npos) { eni.current_emotion = Emotions::Tenderness; }
		if (user.message.find(keys_defiance[i]) != std::string::npos) { eni.current_emotion = Emotions::Defiance; }
		if (user.message.find(keys_euphoria[i]) != std::string::npos) { eni.current_emotion = Emotions::Euphoria; }
	}

	eni.response += EMOTION[eni.current_emotion];

	return 0;
}	
