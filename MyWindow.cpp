#include "MyWindow.h"
#include "Kana.h"
#include <gtkmm.h>
#include <gtkmm/box.h>
#include <iostream>

MyWindow::MyWindow() {
    set_title("Kana Practice");
    set_default_size(600, 400);

    Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL, 10);
    set_kana(Kana::getRandomKana());

    label.set_halign(Gtk::Align::FILL);
    label.set_valign(Gtk::Align::FILL);
    label.set_hexpand(true);
    label.set_vexpand(true);
    box.append(label);

    box.set_margin(5);
    box.append(txtInput);

    Glib::RefPtr<Gtk::EventControllerKey> controller = Gtk::EventControllerKey::create();
    controller->set_propagation_phase(Gtk::PropagationPhase::CAPTURE);
    controller->signal_key_pressed().connect(
            sigc::bind(sigc::mem_fun(*this, &MyWindow::on_key_event), "capture"), false);
    txtInput.add_controller(controller);

    Gtk::HeaderBar headerBar;

    accLabel.set_text("  정확도: 100%");
    headerBar.pack_start(accLabel);
    set_titlebar(headerBar);

    set_child(box);
}

std::string MyWindow::make_markup(const std::string &word) {
    return "<span font=\"80\">" + word + "</span>";
}

bool MyWindow::on_key_event(guint keyval, guint, Gdk::ModifierType, const Glib::ustring &phase) {
    testNum += 1;
    const guint KEY_ENTER = 65293;
    if (keyval == KEY_ENTER) {
        std::string ch = txtInput.get_text().substr(0, 1);
        std::cout << "ch:" << ch << ", kana:" << kana << ", tohan:" << Kana::kanaToHangul(kana) << std::endl;
        if (ch == "") return false;
        if (Kana::kanaToHangul(kana) == ch) {
            set_kana(Kana::getRandomKana());
            txtInput.set_text("");
        } else {
            failNum += 1;
        }
        std::ostringstream accStr;
        accStr.precision(2);
        accStr << "  정확도: " << std::fixed << get_accuracy() << "%";
        accLabel.set_text(accStr.str());
    }
    return false;
}

void MyWindow::set_kana(const std::string &kana) {
    this->kana = kana;
    label.set_markup(make_markup(kana));
}

double MyWindow::get_accuracy() const {
    return  1 - (double) failNum / (double) testNum;
}