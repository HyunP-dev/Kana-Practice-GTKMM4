#ifndef KANA_PRACTICE_MYWINDOW_H
#define KANA_PRACTICE_MYWINDOW_H

#include <gtkmm.h>

class MyWindow : public Gtk::Window {
public:
    MyWindow();

    void set_kana(const std::string& kana);
protected:
    Gtk::Entry txtInput;
    Gtk::Label label;
    Gtk::Label accLabel;
    std::string kana;

    double testNum = 0;
    double failNum = 0;
private:
    static std::string make_markup(const std::string& word);
    bool on_key_event(guint keyval, guint, Gdk::ModifierType, const Glib::ustring& phase);
    double get_accuracy() const;
};


#endif
