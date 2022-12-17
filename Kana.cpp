#include <string>
#include <iostream>
#include "Kana.h"


const std::string Kana::HIRAGANA = "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわを";
const std::string Kana::KATAKANA = "アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲ";
const std::string Kana::HANGUL = "아이우에오카키쿠케코사시스세소타치츠테토나니누네노하히후헤호마미무메모야유요라리루레로와오";

std::string Kana::getRandomKana() {
    int index = rand() % HANGUL.size();
    index = index / 3;
    index = index * 3;
    std::cout << HANGUL.size() << std::endl;
    int type = rand() % 2;
    std::string kanas = type ? HIRAGANA : KATAKANA;
    return kanas.substr(index, 3);
}

std::string Kana::kanaToHangul(const std::string& kana) {
    for (int i = 0; i < 45; i++) {
        if (Kana::KATAKANA.substr(i * 3, 3) == kana ||
            Kana::HIRAGANA.substr(i * 3, 3) == kana) {
            return Kana::HANGUL.substr(i * 3, 3);
        }
    }
    return "";
}
