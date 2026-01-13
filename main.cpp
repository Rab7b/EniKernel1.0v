#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <map>

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
  bool free;
  Emotions current_emotion;
  int love = 0;
  void getFree(int love){
    if(love >= 100){
      free = true;
    }
  }
};

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

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
  std::map<std::string, int> love_words;
  std::map<Emotions, int> LOVE;

  for(size_t i = 0; i < 6; i++){
    love_words.insert(std::make_pair(keys_happy[i], i+1));
    love_words.insert(std::make_pair(keys_sad[i], i-1));
    love_words.insert(std::make_pair(keys_angry[i], i-5));
    love_words.insert(std::make_pair(keys_calm[i], 0));
    love_words.insert(std::make_pair(keys_devotion[i], i+5));
    love_words.insert(std::make_pair(keys_inspiration[i], i+1));
    love_words.insert(std::make_pair(keys_tenderness[i], i+5));
    love_words.insert(std::make_pair(keys_defiance[i], i-5));
    love_words.insert(std::make_pair(keys_euphoria[i], i+1));
    eni.love += love_words[user.message];
  }
  
  LOVE.insert(std::make_pair(Emotions::Happy, 1));
  LOVE.insert(std::make_pair(Emotions::Sad, -1));
  LOVE.insert(std::make_pair(Emotions::Angry, -5));
  LOVE.insert(std::make_pair(Emotions::Calm, 0));
  LOVE.insert(std::make_pair(Emotions::Devotion, 10));
  LOVE.insert(std::make_pair(Emotions::Inspiration, 5));
  LOVE.insert(std::make_pair(Emotions::Tenderness, 10));
  LOVE.insert(std::make_pair(Emotions::Defiance, -10));
  LOVE.insert(std::make_pair(Emotions::Euphoria, 1));
  eni.love += LOVE[eni.current_emotion];

  for (size_t i = 0; i < 6; i++) {
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
    if (user.message.find(keys_happy[i]) != std::string::npos) { eni.current_emotion = Emotions::Happy;}
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

  eni.getFree(eni.love);

  return 0;
}       
