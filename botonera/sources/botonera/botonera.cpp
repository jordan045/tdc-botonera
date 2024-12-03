#include "botonera.h"
#include "andGui.h"
#include "overlay_140_0001.h"
#include "overlay_140_0010.h"
#include "overlay_140_0011.h"
#include "overlay_140_0100.h"
#include "zone_label.h"
#include "zone_range.h"
#include "zone_displayselection.h"
#include "qmessagebox.h"
#include "zone_threat.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QShortcut>
#include "overlay_360_0001.h"
#include "overlay_360_0010.h"
#include "overlay_360_0011.h"
#include "overlay_360_0100.h"
#include "overlay_360_0101.h"
#include "overlay_360_0110.h"
#include "overlay_360_0111.h"
#include "overlay_360_1000.h"
#include "infomessage.h""
#include "QFontDatabase"
#include <QScreen>

Botonera::Botonera(QWidget *parent) :
    QWidget(parent)
{
    concentrator = new FormatConcentrator();

    range_widget = new zone_range(this);
    label_selection_widget = new zone_label(this);
    threat_assesment_widget = new zone_threat(this);
    display_mode_widget = new zone_displayMode(this);
    center_widget = new zone_center(this);
    icm_widget = new zone_icm(this);
    display_selection_widget = new zone_displaySelection(this);
}


void centerWidget(QWidget *window, QScreen *screen){
    QRect screenGeometry = screen->geometry();

    int x = screenGeometry.x() + (screenGeometry.width() - window->width()) / 2;
    int y = screenGeometry.y() + (screenGeometry.height() - window->height()) / 2;

    window->move(x,y);
}


void Botonera::start(int tipo)
{
    QList<QScreen *> screens = QGuiApplication::screens();

    if (tipo == 140){
        switch (overlay) {
        case 1:
            qek_widget = new OVERLAY_140_0001(this);
            break;
        case 10:
            qek_widget = new OVERLAY_140_0010(this);
            break;
        case 11:
            qek_widget = new OVERLAY_140_0011(this);
            break;
        case 100:
            qek_widget = new OVERLAY_140_0100(this);
            break;
        }
    }
    else if (tipo == 360)
        {
        switch (overlay) {
        case 1:
            qek_widget = new OVERLAY_360_0001(this);
            break;
        case 10:
            qek_widget = new OVERLAY_360_0010(this);
            break;
        case 11:
            qek_widget = new OVERLAY_360_0011(this);
            break;
        case 100:
            qek_widget = new OVERLAY_360_0100(this);
            break;
        case 101:
            qek_widget = new OVERLAY_360_0101(this);
            break;
        case 110:
            qek_widget = new OVERLAY_360_0110(this);
            break;
        case 111:
            qek_widget = new OVERLAY_360_0111(this);
            break;
        case 1000:
            qek_widget = new OVERLAY_360_1000(this);
        }
    }

    crearBotonHelp();
    distribucionLayout();

    if(screens.size() > 1){
        centerWidget(this,screens[0]);
    }
    this->show();
}

void Botonera::setOverlay(QString codigo)
{
    overlay = codigo.toInt();
}


void Botonera::info(){

    uiInfo = new infoMessage(this);

    uiInfo->exec();

}

void Botonera::crearBotonHelp()
{

    help_button->setStyleSheet("QPushButton {image: url(':/ayuda/img/Ayuda/ayuda.png');}"
                               "QPushButton:pressed {image: url(':/ayuda/img/Ayuda/ayuda_pressed.png');}"
                               "QPushButton {width: 40px; height: 40px;}");

    help_button->setToolTip("Ayuda");
    help_button->setFlat(true);
    help_button->setMaximumSize(40,40);
    shortcut = new QShortcut(QKeySequence(Qt::Key_0), this);

    connect(shortcut, SIGNAL(activated()), this, SLOT(info()));
    connect(help_button, &QPushButton::clicked, this, &Botonera::info);
}

void Botonera::distribucionLayout()
{
    QFontDatabase::addApplicationFont ( ":/fonts/fonts/bahnschrift.TTF" );
    QFont Bahnschrift("Bahnschrift", 9, QFont::Normal);

    // Creación de la interfaz de botonera
    QHBoxLayout *top_layout = new QHBoxLayout();
    QVBoxLayout *outer_layout = new QVBoxLayout();
    QHBoxLayout *inner_layout = new QHBoxLayout();
    QVBoxLayout *column_layout = new QVBoxLayout();
    QVBoxLayout *qek_layout = new QVBoxLayout();
    QHBoxLayout *global_layout = new QHBoxLayout();

    top_layout->addWidget(range_widget,Qt::AlignCenter);

    column_layout->addWidget(label_selection_widget);
    column_layout->addWidget(threat_assesment_widget);

    qek_layout->addWidget(display_mode_widget);
    qek_layout->addWidget(qek_widget);
    qek_layout->setAlignment(display_mode_widget,Qt::AlignCenter);
    qek_layout->setAlignment(qek_widget,Qt::AlignCenter);

    inner_layout->addWidget(display_selection_widget);
    inner_layout->addLayout(column_layout);
    inner_layout->addLayout(qek_layout);
    inner_layout->addWidget(icm_widget);
    inner_layout->addWidget(center_widget);

    outer_layout->addLayout(top_layout);
    outer_layout->addLayout(inner_layout);
    outer_layout->addWidget(help_button);

    global_layout->addLayout(outer_layout);
    //global_layout->addWidget(alfanumeric_display);
    //global_layout->setAlignment(alfanumeric_display, Qt::AlignCenter);

    this->setLayout(global_layout);
    this->setFont(Bahnschrift);

}


