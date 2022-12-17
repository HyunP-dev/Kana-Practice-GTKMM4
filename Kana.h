#ifndef KANA_PRACTICE_KANA_H
#define KANA_PRACTICE_KANA_H


class Kana {
private:
    static const std::string HIRAGANA;
    static const std::string KATAKANA;
    static const std::string HANGUL;
public:
    static std::string getRandomKana();

    static std::string kanaToHangul(const std::string& kana);
};


#endif
