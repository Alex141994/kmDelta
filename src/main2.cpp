
#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>

//#include "controlip.h"
#include "vmConfigsChat.h"
//#include "ipAddr.h"
//#include "mbtcpClient.h"

int main(int argc, char *argv[])
{
    // Qt Charts uses Qt Graphics View Framework for drawing, therefore QApplication must be used.
    QApplication app(argc, argv);
    //    QQuickView viewer;
    QQmlApplicationEngine engine;//(/*QUrl("qrc:/main2.qml")*/);
//    MbtcpClient *mc = nullptr;
    configs cs("config.ini");// = new configs();
    //vmConfigsChat vm(&cs, &mc);
    vmConfigsChat vmCC(&cs/*, mc*/);

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("vmConfigsChat", &vmCC);

// The following are needed to make examples run without having to install the module
// in desktop environments.
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif

//#if QT_VERSION_MAJOR
//#endif

#if QT_VERSION >= 0x060000
    engine.load(QUrl("qrc:/main.qml"));
#else
    engine.load(QUrl("qrc:/main_5.qml"));
#endif


    return app.exec();
}
